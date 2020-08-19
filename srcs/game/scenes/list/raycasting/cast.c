/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:06:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 18:31:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "maths/maths.h"

static t_bool	is_hitting(const t_map *const map, const t_vec2i ray)
{
	if (ray.x < 0 || ray.y < 0)
		return (TRUE);
	if (ray.x >= (int)map->size.x || ray.y >= (int)map->size.y)
		return (TRUE);
	if (map->map[ray.y * map->size.x + ray.x].texture_ref)
		return (TRUE);
	return (FALSE);
}

static void		init_raycast(t_raycast *const self,
					const t_vec2f pos,
					const t_vec2f dir)
{
	self->delta_distance.x = ft_fabs(1.0f / dir.x);
	self->delta_distance.y = ft_fabs(1.0f / dir.y);
	self->ray_position.x = (int)pos.x;
	self->ray_position.y = (int)pos.y;
	if (dir.x < 0.0f)
	{
		self->step.x = -1;
		self->distance_from_origin.x = (pos.x - self->ray_position.x)
			* self->delta_distance.x;
	}
	else
	{
		self->step.x = 1;
		self->distance_from_origin.x = (self->ray_position.x + 1.0f - pos.x)
			* self->delta_distance.x;
	}
	if (dir.y < 0.0f)
	{
		self->step.y = -1;
		self->distance_from_origin.y = (pos.y - self->ray_position.y)
			* self->delta_distance.y;
	}
	else
	{
		self->step.y = 1;
		self->distance_from_origin.y = (self->ray_position.y + 1.0f - pos.y)
			* self->delta_distance.y;
	}
}

t_ray	cast(const t_map *const map,
			const t_vec2f pos,
			const t_vec2f dir)
{
	t_raycast	raycast;
	t_u8	side;
	t_bool	hit;
	float	wall;
	float	distance;
	t_ray	result;

	init_raycast(&raycast, pos, dir);
	hit = FALSE;
	while (!hit)
	{
		if (raycast.distance_from_origin.x < raycast.distance_from_origin.y)
		{
			raycast.distance_from_origin.x += raycast.delta_distance.x;
			raycast.ray_position.x += raycast.step.x;
			side = 0;
		}
		else
		{
			raycast.distance_from_origin.y += raycast.delta_distance.y;
			raycast.ray_position.y += raycast.step.y;
			side = 1;
		}
		hit = is_hitting(map, raycast.ray_position);
	}
	if (side == 0)
		distance = (raycast.ray_position.x - pos.x + (1.0f - raycast.step.x) / 2.0f) / dir.x;
	else
		distance = (raycast.ray_position.y - pos.y + (1.0f - raycast.step.y) / 2.0f) / dir.y;
	if (side == 0)
		wall = pos.y + distance * dir.y;
	else
		wall = pos.x + distance * dir.x;
	result.hit = ft_vec2f(raycast.ray_position.x, raycast.ray_position.y);
	result.perpendicular_distance = distance;
	result.horizontal_ratio = wall - (int)wall;
	if (side == 0 && raycast.step.x == -1)
		result.horizontal_ratio = 1.0f - result.horizontal_ratio;
	return (result);
}
