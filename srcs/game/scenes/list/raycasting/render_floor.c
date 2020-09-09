/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:06:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 11:13:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "maths/maths.h"
#include "game/scenes/raycasting_scene.h"

static float	get_floor_distance(t_raycasting_scene *const self,
					t_frame *const fb,
					const t_usize i)
{
	float	distance;

	distance = (fb->size.y / (2.0f / (1.0f
		+ self->entities.player_ref->super.transform.position.z * 2)))
		/ (i.y - self->entities.player_ref->super.transform.rotation.x
		- fb->size.y / 2.0f);
	return (distance);
}

static t_vec2f	floor_pos_distance(t_raycasting_scene *const self,
					const float distance,
					const t_vec2f dir,
					const t_vec2f plane)
{
	t_vec2f	floor;

	floor.x = self->entities.player_ref->super.transform.position.x
		+ distance * (dir.x - plane.x);
	floor.y = self->entities.player_ref->super.transform.position.y
		+ distance * (dir.y - plane.y);
	return (floor);
}

static t_rgba	get_floor_color(t_raycasting_scene *const self,
					const t_vec2f floor,
					const float distance)
{
	t_frame	*floor_texture;
	t_vec2i	t;
	t_rgba	color;
	t_rgba	result;
	float	luminosity;

	floor_texture = &block_from_key(self->map.floor)->texture;
	t.x = (int)(floor_texture->size.x * (floor.x - (int)(floor.x)))
		& (floor_texture->size.x - 1);
	t.y = (int)(floor_texture->size.y * (floor.y - (int)(floor.y)))
		& (floor_texture->size.y - 1);
	color = floor_texture->pixels[floor_texture->size.x * t.y + t.x];
	result = get_lerp_col(color, distance, self->darkness);
	if (floor.x < 0.0f || floor.x > self->map.size.x
		|| floor.y < 0.0f || floor.y > self->map.size.y)
		return (result);
	luminosity = raycasting_scene_luminosity_from_light_sources(self,
		ft_vec3f(floor.x, floor.y, 0.0f));
	result.c.r += (255 - result.c.r) * luminosity / 6.0f * 0.984f;
	result.c.g += (255 - result.c.g) * luminosity / 6.0f * 0.949f;
	result.c.b += (255 - result.c.b) * luminosity / 6.0f * 0.8f;
	result.c.a = color.c.a;
	return (result);
}

void			raycasting_scene_render_floor(t_raycasting_scene *const self,
					t_frame *const fb,
					const t_vec2f dir,
					const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	floor;
	float	dst;
	t_rgba	color;

	if (self->entities.player_ref->super.transform.position.z <= -0.5f)
		return ;
	i.y = fb->size.y / 2
		+ self->entities.player_ref->super.transform.rotation.x;
	while (i.y < fb->size.y)
	{
		dst = get_floor_distance(self, fb, i);
		floor = floor_pos_distance(self, dst, dir, plane);
		i.x = 0;
		while (i.x < fb->size.x)
		{
			floor.x += dst * (dir.x + plane.x - (dir.x - plane.x)) / fb->size.x;
			floor.y += dst * (dir.y + plane.y - (dir.y - plane.y)) / fb->size.x;
			color = get_floor_color(self, floor, dst);
			fb->pixels[i.y * fb->size.x + i.x] =
				blend_add(fb->pixels[i.y * fb->size.x + i.x], color);
			i.x++;
		}
		i.y++;
	}
}
