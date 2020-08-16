/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 04:02:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/menu_scene.h"
#include "engine/delta.h"
#include "game/game.h"

static void	zbuffer(t_raycasting_scene *const self,
				const t_vec2f dir,
				const t_vec2f plane)
{
	size_t	i;
	size_t	length;
	float	camera_x;
	t_ray	*buffer;

	length = self->zbuffer.size / sizeof(t_ray);
	buffer = (t_ray*)self->zbuffer.array;
	i = 0;
	while (i < length)
	{
		camera_x = 2.0f * i / (float)length - 1;
		buffer[i] = cast(&self->map,
			ft_vec2f(self->entities.player_ref->super.transform.position.x,
				self->entities.player_ref->super.transform.position.y),
			ft_vec2f(dir.x + plane.x * camera_x, dir.y + plane.y * camera_x));
		i++;
	}
}

static void	remove_door(t_raycasting_scene *const self, char id)
{
	t_usize	i;

	i.y = 0;
	while (i.y < self->map.size.y)
	{
		i.x = 0;
		while (i.x < self->map.size.x)
		{
			if (self->map.map[self->map.size.x * i.y + i.x].id == id)
			{
				self->map.map[self->map.size.x * i.y + i.x].id = ' ';
				self->map.map[self->map.size.x * i.y + i.x].texture_ref = NULL;
				zbuffer(self, self->entities.player_ref->dir, self->entities.player_ref->plane);
			}
			i.x++;
		}
		i.y++;
	}
}

static void	door_trigger(t_raycasting_scene *const self)
{
	t_game	*game;
	t_ray	*zbuffer;
	t_ray	*mid_ray;
	t_wall	*wall;

	game = game_singleton();
	if (input_get(&game->input, self->inputs.use) > 0.0f)
	{
		zbuffer = (t_ray*)self->zbuffer.array;
		mid_ray = &zbuffer[self->window_ref->size.x / 2];
		if (mid_ray->perpendicular_distance < 2.0f)
		{
			wall = &self->map.map[(int)mid_ray->hit.y * self->map.size.x
				+ (int)mid_ray->hit.x];
			if (wall->id == game->blocks_list.metallic_red_button.id)
				remove_door(self, game->blocks_list.metallic_red_door.id);
			if (wall->id == game->blocks_list.metallic_green_button.id)
				remove_door(self, game->blocks_list.metallic_green_door.id);
			if (wall->id == game->blocks_list.metallic_blue_button.id)
				remove_door(self, game->blocks_list.metallic_blue_door.id);
		}
	}
}

#include <stdio.h>

static void	pick_weapon(t_raycasting_scene *const self)
{
	t_list_head		*node;
	t_weapon_entity	*weapon;
	float			distance;

	node = &self->weapon_entities.list;
	while ((node = node->next) != &self->weapon_entities.list)
	{
		weapon = (t_weapon_entity*)((t_entity_node*)node)->entity;
		if (weapon->is_picked)
		{
			weapon = NULL;
			continue ;
		}
		distance = vec3f_squared_distance(
			weapon->super.super.transform.position,
			self->entities.player_ref->super.transform.position);
		if (distance < 1.0f)
			break ;
		weapon = NULL;
	}
	if (input_get(&game_singleton()->input, self->inputs.pick) > 0.0f)
	{
		if (self->entities.weapon_ref)
		{
			self->entities.weapon_ref->super.super.transform.position =
				self->entities.player_ref->super.transform.position;
			self->entities.weapon_ref->super.super.transform.position.z = 0.0f;
		}
		self->weapon.nearest_weapon = self->entities.weapon_ref;
		self->entities.weapon_ref = weapon;
		if (self->entities.weapon_ref)
			self->entities.weapon_ref->first_render = TRUE;
	}
	else
		self->weapon.nearest_weapon = weapon;
}

void		raycasting_scene_update(t_raycasting_scene *const self)
{
	// printf("weapons: %lu\n", list_size(&self->weapon_entities.list));
	// printf("before entity update (%lu)\n", list_size(&self->super.entities.list));
	entity_list_update(&self->super.entities);
	// printf("after entity update  (%lu)\n", list_size(&self->super.entities.list));
	if (self->entities.retry_button_ref->is_clicked)
	{
		game_set_scene(raycasting_scene(self->window_ref, self->path));
		return ;
	}
	if (self->entities.give_up_button_ref->is_clicked)
	{
		// printf("gave up lol\n");
		game_set_scene(menu_scene(self->window_ref, self->path));
		return ;
	}
	if (self->entities.player_ref->is_dead && self->death_time == 0.0f)
		self->death_time = get_wall_time();
	zbuffer(self, self->entities.player_ref->dir, self->entities.player_ref->plane);
	if (!self->entities.player_ref->is_dead)
	{
		if (self->entities.weapon_ref)
		{
			if (input_get(&game_singleton()->input,
				self->inputs.reload) > 0.0f
				&& self->entities.weapon_ref->shooting == FALSE
				&& !self->entities.weapon_ref->reloading
				&& self->entities.weapon_ref->specs.clip
					!= self->entities.weapon_ref->specs.clip_size)
				self->entities.weapon_ref->trigger_reloading = TRUE;
			if (self->entities.weapon_ref->just_reloaded)
				raycasting_scene_weapon_reload(self);
			else if (input_get(&game_singleton()->input, self->inputs.shoot) > 0.0f
				&& !self->entities.weapon_ref->reloading)
				raycasting_scene_weapon_use(self);
			else
			{
				self->entities.weapon_ref->stopped_shooting = TRUE;
				self->entities.weapon_ref->loading = FALSE;
				self->entities.weapon_ref->load_start = 0.0;
			}
		}
		door_trigger(self);
	}
	pick_weapon(self);
	animation_update(&self->assets.use_key_animation, &self->assets.use_key_spritesheet);
	// cursor_set_pos(&self->window_ref->cursor, self->window_ref->window,
	// 	ft_isize(self->window_ref->size.x / 2, self->window_ref->size.y / 2));
}
