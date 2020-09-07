/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 00:42:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:35:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

static t_wall		*wall_at_pos(const t_raycasting_scene *const self,
						const t_vec2f pos)
{
	if (pos.x >= self->map.size.x || pos.y >= self->map.size.y
		|| pos.x < 0 || pos.y < 0)
		return (NULL);
	else
		return (&self->map.map[(int)pos.y * self->map.size.x
			+ (int)pos.x]);
}

static float		render_column(t_raycasting_scene *const self,
						t_frame *const fb,
						const float last_distance)
{
	t_ray			ray;
	t_wall			*wall;
	const t_frame	*texture;

	ray = ft_ray(&self->raycasting.column,
		progress(&self->map, &self->raycasting.column));
	if (!(wall = wall_at_pos(self, ray.hit)))
		texture = &self->assets.floor;
	else
	{
		texture = wall->texture_ref;
		if (wall->translucent || self->entities.player_ref->is_flying)
			render_column(self, fb, ray.perpendicular_distance);
	}
	raycasting_scene_render_wall_column(self, fb, &ray, texture);
	raycasting_scene_render_sprite_column(self, fb, &ray, last_distance);
	return (ray.perpendicular_distance);
}

void				raycasting_scene_render_map(t_raycasting_scene *const self,
						t_frame *const fb)
{
	size_t	x;
	float	camera_x;
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	plane;

	x = 0;
	while (x < fb->size.x)
	{
		camera_x = 2.0f * x / (float)fb->size.x - 1;
		pos = ft_vec2f(self->entities.player_ref->super.transform.position.x,
			self->entities.player_ref->super.transform.position.y);
		plane = self->entities.player_ref->plane;
		dir = self->entities.player_ref->dir;
		dir = ft_vec2f(dir.x + plane.x * camera_x, dir.y + plane.y * camera_x);
		init_raycast(&self->raycasting.column, pos, dir);
		raycasting_scene_sort_sprites(self);
		self->raycasting.x = x;
		render_column(self, fb, 0.0f);
		x++;
	}
}
