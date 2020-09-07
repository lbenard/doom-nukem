/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:21:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 13:07:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "maths/maths.h"
#include "game/scenes/raycasting_scene.h"

static float	darkness(t_raycasting_scene *const self)
{
	float	time;

	time = get_wall_time() - self->weapon.last_shot;
	if (time >= 0.0f && time <= 0.3f)
		return (2.0f * (time * 3.33f));
	return (2.0f);
}

static float	get_ceiling_distance(t_raycasting_scene *const self,
					t_frame *const fb,
					const t_usize i)
{
	float	distance;

	distance = (fb->size.y / (2.0f / (1.0f
		- self->entities.player_ref->super.transform.position.z * 2)))
		/ (i.y + self->entities.player_ref->super.transform.rotation.x
		- fb->size.y / 2.0f);
	return (distance);
}

static t_vec2f	ceiling_pos_distance(t_raycasting_scene *const self,
					const float distance,
					const t_vec2f dir,
					const t_vec2f plane)
{
	t_vec2f	ceiling;

	ceiling.x = self->entities.player_ref->super.transform.position.x + distance
		* (dir.x - plane.x);
	ceiling.y = self->entities.player_ref->super.transform.position.y + distance
		* (dir.y - plane.y);
	return (ceiling);
}

static t_rgba	get_ceiling_color(t_raycasting_scene *const self,
					const t_vec2f ceiling,
					const float distance,
					const float darkness)
{
	t_vec2i	t;
	t_rgba	c;
	t_rgba	result;
	float	luminosity;

	t.x = (int)(self->assets.ceiling.size.x * (ceiling.x - (int)(ceiling.x)))
		& (self->assets.ceiling.size.x - 1);
	t.y = (int)(self->assets.ceiling.size.y * (ceiling.y - (int)(ceiling.y)))
		& (self->assets.ceiling.size.y - 1);
	c = self->assets.ceiling.pixels[self->assets.ceiling.size.x * t.y + t.x];
	result = get_lerp_col(c, distance, darkness);
	if (ceiling.x < 0.0f || ceiling.x > self->map.size.x
		|| ceiling.y < 0.0f || ceiling.y > self->map.size.y)
		return (result);
	luminosity = raycasting_scene_luminosity_from_light_sources(self,
		ft_vec3f(ceiling.x, ceiling.y, 1.0f));
	result.c.r += (255 - result.c.r) * luminosity / 6.0f * 0.984f;
	result.c.g += (255 - result.c.g) * luminosity / 6.0f * 0.949f;
	result.c.b += (255 - result.c.b) * luminosity / 6.0f * 0.8f;
	return (result);
}

void			raycasting_scene_render_ceiling(t_raycasting_scene *const self,
					t_frame *const fb,
					const t_vec2f dir,
					const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	ceil;
	float	dst;
	float	darkness_value;

	if (self->entities.player_ref->super.transform.position.z >= 0.5f)
		return ;
	darkness_value = darkness(self);
	i.y = fb->size.y / 2
		- self->entities.player_ref->super.transform.rotation.x;
	while (i.y < fb->size.y)
	{
		dst = get_ceiling_distance(self, fb, i);
		ceil = ceiling_pos_distance(self, dst, dir, plane);
		i.x = 0;
		while (i.x < fb->size.x)
		{
			ceil.x += dst * (dir.x + plane.x - (dir.x - plane.x)) / fb->size.x;
			ceil.y += dst * (dir.y + plane.y - (dir.y - plane.y)) / fb->size.x;
			fb->pixels[(fb->size.y - i.y - 1) * fb->size.x + i.x] =
				get_ceiling_color(self, ceil, dst, darkness_value);
			i.x++;
		}
		i.y++;
	}
}
