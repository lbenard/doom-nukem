/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:25:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:34:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

static t_rgba	get_sprite_color(const t_raycasting_scene *const self,
					const t_sprite_entity *const sprite,
					const t_usize sprite_px)
{
	t_rgba	sprite_color;
	t_rgba	result;
	float	time;
	float	darkness_value;
	float	luminosity;

	time = get_wall_time() - self->weapon.last_shot;
	sprite_color = sprite->texture.pixels
		[sprite_px.y * sprite->texture.size.x + sprite_px.x];
	if (time >= 0.0f && time <= 0.3f)
		darkness_value = 2.0f * (time * 3.33f);
	else
		darkness_value = 2.0f;
	result = get_lerp_col(sprite_color,
		sprite->perpendicular_distance,
		darkness_value);
	result.c.a = sprite_color.c.a;
	luminosity = raycasting_scene_luminosity_from_light_sources(self,
		sprite->super.transform.position);
	result.c.r += (255 - result.c.r) * luminosity / 6.0f * 0.984f;
	result.c.g += (255 - result.c.g) * luminosity / 6.0f * 0.949f;
	result.c.b += (255 - result.c.b) * luminosity / 6.0f * 0.8f;
	return (result);
}

static t_bool	is_sprite_visible(const t_raycasting_scene *const self,
					const t_sprite_entity *const sprite,
					const float last_distance,
					const t_ray *const ray)
{
	return (sprite->is_visible
		&& sprite->perpendicular_distance < ray->perpendicular_distance
		&& sprite->perpendicular_distance > last_distance
		&& (ssize_t)self->raycasting.x < sprite->end_x
		&& (ssize_t)self->raycasting.x > sprite->start_x);
}

void			raycasting_scene_render_sprite_column(
					const t_raycasting_scene *const self,
					t_frame *const fb,
					t_ray *const ray,
					const float last_distance)
{
	const t_list_head		*pos;
	const t_sprite_entity	*sprite;
	t_usize					sprite_px;
	size_t					y;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		if (is_sprite_visible(self, sprite, last_distance, ray))
		{
			sprite_px.x = inverse_lerp(sprite->start_x, sprite->end_x,
				self->raycasting.x) * sprite->texture.size.x;
			y = (size_t)ft_ssmax(sprite->start_y, 0);
			while ((ssize_t)y < sprite->end_y && y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(sprite->start_y, sprite->end_y, y)
					* sprite->texture.size.y;
				fb->pixels[y * fb->size.x + self->raycasting.x] =
					blend_add(fb->pixels[y * fb->size.x + self->raycasting.x],
						get_sprite_color(self, sprite, sprite_px));
				y++;
			}
		}
	}
}
