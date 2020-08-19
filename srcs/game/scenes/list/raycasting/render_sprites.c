/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 22:13:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 03:55:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "maths/maths.h"
#include "engine/delta.h"

static void		sort(t_raycasting_scene *const self)
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

static t_rgba	get_sprite_color(t_raycasting_scene *const self,
					const t_sprite_entity *const sprite,
					const t_usize sprite_px)
{
	t_rgba			sprite_color;
	t_rgba			saturated_color;
	float			time;
	float			darkness_value;

	time = get_wall_time() - self->weapon.last_shot;
	sprite_color = sprite->texture.pixels
		[sprite_px.y * sprite->texture.size.x + sprite_px.x];
	if (time >= 0.0f && time <= 0.3f)
		darkness_value = 2.0f * (time * 3.33f);
	else
		darkness_value = 2.0f;
	saturated_color = get_lerp_col(sprite_color,
		sprite->perpendicular_distance,
		darkness_value);
	saturated_color.c.a = sprite_color.c.a;
	return (saturated_color);
}

static void		render_sprite(t_raycasting_scene *const self,
					t_frame *const fb,
					const t_sprite_entity *const sprite)
{
	t_usize	i;
	t_usize	sprite_px;

	i.x = (size_t)ft_ssmax(sprite->start_x, 0);
	while ((ssize_t)i.x < sprite->end_x && i.x < fb->size.x)
	{
		if (sprite->perpendicular_distance
			< ((t_ray*)self->zbuffer.array)[i.x].perpendicular_distance)
		{
			sprite_px.x = inverse_lerp(sprite->start_x, sprite->end_x, i.x)
				* sprite->texture.size.x;
			i.y = (size_t)ft_ssmax(sprite->start_y, 0);
			while ((ssize_t)i.y < sprite->end_y && i.y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(sprite->start_y, sprite->end_y, i.y)
					* sprite->texture.size.y;
				fb->pixels[i.y * fb->size.x + i.x] = blend_add(
					fb->pixels[i.y * fb->size.x + i.x],
					get_sprite_color(self, sprite, sprite_px));
				i.y++;
			}
		}
		i.x++;
	}
}

static void		render_sprites(t_raycasting_scene *const self,
					t_frame *const fb)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		if (sprite->is_visible)
			render_sprite(self, fb, sprite);
	}
}

void			raycasting_scene_render_sprites(t_raycasting_scene *const self,
					t_frame *const fb)
{
	t_list_head			*pos;
	t_monster_entity	*monster;
	t_u8				distance_opacity;

	sort(self);
	render_sprites(self, fb);
	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.perpendicular_distance > 10.0f
			|| !monster->super.is_visible)
			continue ;
		distance_opacity = inverse_lerp(10.0f, 0.0f,
			monster->super.perpendicular_distance) * 255;
		monster_entity_render_name(monster, fb, distance_opacity);
		if (monster->health < monster->full_health)
			monster_entity_render_health(monster, fb, distance_opacity);
	}
}
