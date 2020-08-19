/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:06:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 18:53:26 by lbenard          ###   ########.fr       */
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
	self->delta_dist = ft_vec2f(ft_fabs(1.0f / dir.x), ft_fabs(1.0f / dir.y));
	self->ray_pos = ft_vec2i((int)pos.x, (int)pos.y);
	if (dir.x < 0.0f)
	{
		self->step.x = -1;
		self->origin_dist.x = (pos.x - self->ray_pos.x) * self->delta_dist.x;
	}
	else
	{
		self->step.x = 1;
		self->origin_dist.x = (self->ray_pos.x + 1.0f - pos.x)
			* self->delta_dist.x;
	}
	if (dir.y < 0.0f)
	{
		self->step.y = -1;
		self->origin_dist.y = (pos.y - self->ray_pos.y) * self->delta_dist.y;
	}
	else
	{
		self->step.y = 1;
		self->origin_dist.y = (self->ray_pos.y + 1.0f - pos.y)
			* self->delta_dist.y;
	}
}

static t_u8		progress(const t_map *const map, t_raycast *const raycast)
{
	t_bool	hit;
	t_u8	side;

	hit = FALSE;
	while (!hit)
	{
		if (raycast->origin_dist.x < raycast->origin_dist.y)
		{
			raycast->origin_dist.x += raycast->delta_dist.x;
			raycast->ray_pos.x += raycast->step.x;
			side = 0;
		}
		else
		{
			raycast->origin_dist.y += raycast->delta_dist.y;
			raycast->ray_pos.y += raycast->step.y;
			side = 1;
		}
		hit = is_hitting(map, raycast->ray_pos);
	}
	return (side);
}

t_ray			cast(const t_map *const map,
					const t_vec2f pos,
					const t_vec2f dir)
{
	t_raycast	raycast;
	t_u8		side;
	float		wall;
	float		distance;
	t_ray		result;

	init_raycast(&raycast, pos, dir);
	if ((side = progress(map, &raycast)) == 0)
	{
		distance = (raycast.ray_pos.x - pos.x
			+ (1.0f - raycast.step.x) / 2.0f) / dir.x;
		wall = pos.y + distance * dir.y;
	}
	else
	{
		distance = (raycast.ray_pos.y - pos.y
			+ (1.0f - raycast.step.y) / 2.0f) / dir.y;
		wall = pos.x + distance * dir.x;
	}
	result.hit = ft_vec2f(raycast.ray_pos.x, raycast.ray_pos.y);
	result.perpendicular_distance = distance;
	result.horizontal_ratio = wall - (int)wall;
	if ((!side && raycast.step.x == -1) || (side && raycast.step.y == 1))
		result.horizontal_ratio = 1.0f - result.horizontal_ratio;
	return (result);
}
