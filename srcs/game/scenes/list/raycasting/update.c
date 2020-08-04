/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 22:13:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/menu_scene.h"
#include "engine/delta.h"
#include "game/game.h"

#include <stdio.h>

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
			ft_vec2f(self->player_ref->super.transform.position.x,
				self->player_ref->super.transform.position.y),
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
				zbuffer(self, self->player_ref->dir, self->player_ref->plane);
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
	if (input_get(&game->input, self->use_input) > 0.0f)
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

void		raycasting_scene_update(t_raycasting_scene *const self)
{
	entity_list_update(&self->super.entities);
	if (self->retry_button_ref->is_clicked)
	{
		game_set_scene(raycasting_scene(self->window_ref, self->path));
		return ;
	}
	if (self->give_up_button_ref->is_clicked)
	{
		game_set_scene(menu_scene(self->window_ref, self->path));
		return ;
	}
	if (self->player_ref->is_dead && self->death_time == 0.0f)
		self->death_time = get_wall_time();
	self->weapon.just_shooted = FALSE;
	self->weapon.just_reloaded = FALSE;
	zbuffer(self, self->player_ref->dir, self->player_ref->plane);
	if (!self->player_ref->is_dead)
	{
		if (input_get(&game_singleton()->input, self->weapon.reload_input) > 0.0f && self->weapon.shooting == FALSE)
			raycasting_scene_weapon_reload(self);
		if (input_get(&game_singleton()->input, self->weapon.shoot_input) > 0.0f)
			raycasting_scene_weapon_use(self);
		door_trigger(self);
	}
	animation_update(&self->pistol_anim, &self->pistol_ss);
	animation_update(&self->shotgun_anim, &self->shotgun_ss);
	animation_update(&self->minigun_anim, &self->minigun_ss);
	// cursor_set_pos(&self->window_ref->cursor, self->window_ref->window,
	// 	ft_isize(self->window_ref->size.x / 2, self->window_ref->size.y / 2));
	printf("sprites: %lu\n", list_size(&self->sprite_entities.list));
}
