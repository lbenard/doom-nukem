/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:39:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:45:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static t_vec2f	wall_hit(const t_raycast *const raycast,
					const t_u8 side,
					const t_ray *const ray)
{
	t_vec2f	wall_hit;

	wall_hit = ray->hit;
	if (side == 0 && raycast->step.x == -1)
		wall_hit.x += 1.0f;
	if (side == 1 && raycast->step.y == -1)
		wall_hit.y += 1.0f;
	if (side == 1)
		wall_hit.x += ray->horizontal_ratio;
	if (side == 0)
		wall_hit.y += ray->horizontal_ratio;
	return (wall_hit);
}

t_ray			ft_ray(const t_raycast *const raycast, const t_u8 side)
{
	float	wall;
	float	distance;
	t_ray	result;

	if (side == 0)
	{
		distance = (raycast->ray_pos.x - raycast->start_pos.x
			+ (1.0f - raycast->step.x) / 2.0f) / raycast->dir.x;
		wall = raycast->start_pos.y + distance * raycast->dir.y;
	}
	else
	{
		distance = (raycast->ray_pos.y - raycast->start_pos.y
			+ (1.0f - raycast->step.y) / 2.0f) / raycast->dir.y;
		wall = raycast->start_pos.x + distance * raycast->dir.x;
	}
	result.hit = ft_vec2f(raycast->ray_pos.x, raycast->ray_pos.y);
	result.perpendicular_distance = distance;
	result.horizontal_ratio = wall - (int)wall;
	result.wall_hit = wall_hit(raycast, side, &result);
	if ((!side && raycast->step.x == -1) || (side && raycast->step.y == 1))
		result.horizontal_ratio = 1.0f - result.horizontal_ratio;
	return (result);
}
