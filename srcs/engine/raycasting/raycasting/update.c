/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:51:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/04 03:48:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycasting.h"
#include "maths/vec2i.h"

static float	float_abs(float x)
{
	return ((x < 0.0f) ? -x : x);
}

#include <stdio.h>

void	raycasting_update(t_raycasting *const self)
{
	size_t	i;
	t_ray	*ray;
	float	camera_x;
	t_vec2f	ray_dir;
	t_vec2f	delta_dist;
	t_vec2i	map;
	t_vec2f	side_dist;
	t_vec2i	step;
	t_u8	side;
	t_bool	hit;

	i = 0;
	while (i < self->columns_number)
	{
		ray = ((t_ray*)self->columns.array) + i;
		camera_x = 2.0f * i / (float)self->columns_number - 1;
		ray_dir = ft_vec2f(self->dir.x + self->plane.x * camera_x,
			self->dir.y + self->plane.y * camera_x);
		delta_dist = ft_vec2f(float_abs(1.0f / ray_dir.x),
			float_abs(1.0f / ray_dir.y));
		map = ft_vec2i((int)self->pos.x, (int)self->pos.y);
		if (ray_dir.x < 0.0f)
		{
			step.x = -1;
			side_dist.x = (self->pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0f - self->pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0.0f)
		{
			step.y = -1;
			side_dist.y = (self->pos.y - map.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0f - self->pos.y) * delta_dist.y;
		}
		hit = FALSE;
		while (!hit)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map.y += step.y;
				side = 1;
			}
			hit = self->map->map[map.y * self->map->size.x + map.x]
				.north_texture_ref != NULL;
		}
		ray->wall = &self->map->map[map.y * self->map->size.x + map.x];
		ray->start = self->pos;

		// self->columns.array)[i].hit = 
		if (side == 0)
			ray->perpendicular_distance =
				(map.x - self->pos.x + (1.0f - step.x) / 2.0f) / ray_dir.x;
		else
			ray->perpendicular_distance =
				(map.y - self->pos.y + (1.0f - step.y) / 2.0f) / ray_dir.y;
		
		// t_vec2f	wall = ft_vec2f(0.0f, 0.0f); //where exactly the wall was hit
		float	wall;
		if (side == 0)
			wall = self->pos.y
				+ ray->perpendicular_distance
				* ray_dir.y;
		else
			wall = self->pos.x
				+ ray->perpendicular_distance
				* ray_dir.x;
		wall -= (int)wall;
		ray->texture_ratio = wall;
		// printf("hit at %f %f\n", ray->hit.x, ray->hit.y);
		
		i++;
	}
}