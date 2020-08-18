/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 22:13:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 20:43:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "maths/maths.h"
#include "engine/delta.h"

static void	list_swap_next(t_list_head *pos)
{
	t_list_head		*next;
	t_list_head		*left;
	t_list_head		*right;

	next = pos->next;
	left = pos->prev;
	right = next->next;
	left->next = next;
	right->prev = pos;
	pos->prev = next;
	pos->next = right;
	next->prev = left;
	next->next = pos;
}

static void	sort(t_raycasting_scene *const self)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_sprite_entity	*next_sprite;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		if (pos->next == &self->sprite_entities.list)
			break ;
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		next_sprite = (t_sprite_entity*)((t_entity_node*)pos->next)->entity;
		if (sprite->perpendicular_distance
			< next_sprite->perpendicular_distance)
		{
			list_swap_next(pos);
			pos = &self->sprite_entities.list;
			continue ;
		}
	}
}

static void	render_sprites(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_usize			i;
	t_ray			*zbuffer;
	t_usize			sprite_px;
	t_frame			*sprite_texture;
	t_rgba			sprite_color;
	t_rgba			saturated_color;
	float			darkness_value;
	float			time;

	time = get_wall_time() - self->weapon.last_shot;
	zbuffer = (t_ray*)self->zbuffer.array;
	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		sprite_texture = &sprite->texture;
		if (!sprite->is_visible)
			continue ;
		i.x = (size_t)ft_ssmax(sprite->start_x, 0);
		while ((ssize_t)i.x < sprite->end_x && i.x < fb->size.x)
		{
			if (sprite->perpendicular_distance
				>= zbuffer[i.x].perpendicular_distance)
			{
				i.x++;
				continue ;
			}
			sprite_px.x = inverse_lerp(sprite->start_x, sprite->end_x, i.x)
				* sprite_texture->size.x;
			i.y = (size_t)ft_ssmax(sprite->start_y, 0);
			while ((ssize_t)i.y < sprite->end_y && i.y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(sprite->start_y, sprite->end_y, i.y)
					* sprite_texture->size.y;
				sprite_color = sprite_texture->pixels[sprite_px.y
					* sprite_texture->size.x + sprite_px.x];
				if (time >= 0.0f && time <= 0.3f)
					darkness_value = 2.0f * (time * 3.33f);
				else
					darkness_value = 2.0f;
				saturated_color = ft_get_lerp_col(sprite_color, sprite->perpendicular_distance, darkness_value);
				saturated_color.c.a = sprite_color.c.a;
				fb->pixels[i.y * fb->size.x + i.x] =
					blend_add(fb->pixels[i.y * fb->size.x + i.x],
					saturated_color);
				i.y++;
			}
			i.x++;
		}
	}
}

static void	monsters_health(const t_monster_entity *const monster,
				t_frame *const fb,
				const float distance_opacity)
{
	t_frame_coordinates	coordinates;
	t_usize				i;
	t_rgba				*bg;

	coordinates.start.x = monster->super.start_x;
	coordinates.end.x = monster->super.end_x;
	coordinates.start.y = monster->super.start_y;
	coordinates.end.y = monster->super.start_y
		+ (monster->super.end_x - monster->super.start_x) / 20;
	i.y = (size_t)ft_ssmax(coordinates.start.y, 0);
	while ((ssize_t)i.y < coordinates.end.y && i.y < fb->size.y)
	{
		i.x = (size_t)ft_ssmax(coordinates.start.x, 0);
		while ((ssize_t)i.x < coordinates.end.x && i.x < fb->size.x)
		{
			bg = &fb->pixels[i.y * fb->size.x + i.x];
			if ((float)(i.x - coordinates.start.x + i.y - coordinates.start.y)
				/ (float)(coordinates.end.x - coordinates.start.x)
				> monster->health / monster->full_health)
				*bg = blend_add(*bg, ft_rgba(0, 31, 0, distance_opacity));
			else
				*bg = blend_add(*bg, ft_rgba(0, 255, 0, distance_opacity));
			i.x++;
		}
		i.y++;
	}
}

static void	monsters(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_list_head			*pos;
	t_monster_entity	*monster;
	t_u8				distance_opacity;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.perpendicular_distance > 10.0f
			|| !monster->super.is_visible)
			continue ;
		distance_opacity = inverse_lerp(10.0f, 0.0f,
			monster->super.perpendicular_distance) * 255;
		frame_layer_transform_add(fb,
			&monster->name_text.target,
			ft_frame_transform(ft_vec2f(0.5f, 1.0f),
				ft_isize((monster->super.start_x + monster->super.end_x) / 2,
					monster->super.start_y),
				ft_vec2f(10.0f / monster->super.perpendicular_distance
					* monster->super.super.transform.scale.x,
					10.0f / monster->super.perpendicular_distance
					* monster->super.super.transform.scale.y),
				distance_opacity));
		if (monster->health < monster->full_health)
			monsters_health(monster, fb, distance_opacity);
	}
}

void		raycasting_scene_render_sprites(t_raycasting_scene *const self,
				t_frame *const fb)
{
	sort(self);
	render_sprites(self, fb);	
	monsters(self, fb);
}
