/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:06:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 19:42:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "maths/maths.h"

// static t_ray		ft_ray(const t_vec2f hit,
// 						t_wall *const wall,
// 						const float perpendicular_distance,
// 						const float horizontal_ratio)
// {
// 	t_ray	ret;

// 	ret.hit = hit;
// 	ret.wall = wall;
// 	ret.perpendicular_distance = perpendicular_distance;
// 	ret.horizontal_ratio = horizontal_ratio;
// 	return (ret);
// }

// static t_u8			fire(t_casting *const progress, const t_vec2i step)
// {
// 	if (progress->origin_to_side.x < progress->origin_to_side.y)
// 	{
// 		progress->origin_to_side.x += progress->side_to_side.x;
// 		progress->pos.x += step.x;
// 		return (0);
// 	}
// 	else
// 	{
// 		progress->origin_to_side.y += progress->side_to_side.y;
// 		progress->pos.y += step.y;
// 		return (1);
// 	}
// }

// t_ray				cast(const t_map *const map,
// 						const t_vec2f pos,
// 						const t_vec2f dir)
// {
// 	t_casting	progress;
// 	t_vec2i		step;
// 	t_u8		side;
// 	float		wall;
// 	float		distance;

// 	progress.pos = ft_vec2i((int)pos.x, (int)pos.y);
// 	progress.side_to_side = ft_vec2f(ft_fabs(1.0f / dir.x), ft_fabs(1.0f / dir.y));
// 	if (dir.x < 0.0f)
// 	{
// 		step.x = -1;
// 		progress.origin_to_side.x = (pos.x - progress.pos.x)
// 			* progress.side_to_side.x;
// 	}
// 	else
// 	{
// 		step.x = 1;
// 		progress.origin_to_side.x = (progress.pos.x + 1.0f - pos.x)
// 			* progress.side_to_side.x;
// 	}
// 	if (dir.y < 0.0f)
// 	{
// 		step.y = -1;
// 		progress.origin_to_side.y = (pos.y - progress.pos.y)
// 			* progress.side_to_side.y;
// 	}
// 	else
// 	{
// 		step.y = 1;
// 		progress.origin_to_side.y = (progress.pos.y + 1.0f - pos.y)
// 			* progress.side_to_side.y;
// 	}
// 	while (map->map[progress.pos.y * map->size.x + progress.pos.x].north_texture_ref)
// 		side = fire(&progress, step);
// 	if (side == 0)
// 		distance = (progress.pos.x - pos.x + (1.0f - step.x) / 2.0f) / dir.x;
// 	else
// 		distance = (progress.pos.y - pos.y + (1.0f - step.y) / 2.0f) / dir.y;
// 	if (side == 0)
// 		wall = pos.y + distance * dir.y;
// 	else
// 		wall = pos.x + distance * dir.x;
// 	return (ft_ray(
// 		ft_vec2f(progress.pos.x, progress.pos.y),
// 		&map->map[progress.pos.y * map->size.x + progress.pos.x],
// 		distance,
// 		wall - (int)wall));
// }

static t_bool	is_hitting(const t_map *const map, const t_vec2i ray)
{
	// if (ray.x < 0 || ray.y < 0)
	// 	return (TRUE);
	// if (ray.x >= (int)map->size.x || ray.y >= (int)map->size.y)
	// 	return (TRUE);
	if (map->map[ray.y * map->size.x + ray.x].texture_ref)
		return (TRUE);
	return (FALSE);
}
#include <stdio.h>

t_ray	cast(const t_map *const map,
			const t_vec2f pos,
			const t_vec2f dir)
{
	// printf("cast\n");
	t_vec2i	ray_pos;
	t_vec2f	origin_dist;
	t_vec2f	delta_dist;
	t_vec2i	step;
	t_u8	side;
	t_bool	hit;
	float	wall;
	float	distance;
	t_ray	result;

	delta_dist = ft_vec2f(ft_fabs(1.0f / dir.x), ft_fabs(1.0f / dir.y));
	ray_pos = ft_vec2i((int)pos.x, (int)pos.y);
	if (dir.x < 0.0f)
	{
		step.x = -1;
		origin_dist.x = (pos.x - ray_pos.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		origin_dist.x = (ray_pos.x + 1.0f - pos.x) * delta_dist.x;
	}
	if (dir.y < 0.0f)
	{
		step.y = -1;
		origin_dist.y = (pos.y - ray_pos.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		origin_dist.y = (ray_pos.y + 1.0f - pos.y) * delta_dist.y;
	}
	hit = FALSE;
	// printf("searching for wall\n");
	while (!hit)
	{
		if (origin_dist.x < origin_dist.y)
		{
			origin_dist.x += delta_dist.x;
			ray_pos.x += step.x;
			side = 0;
		}
		else
		{
			origin_dist.y += delta_dist.y;
			ray_pos.y += step.y;
			side = 1;
		}
		hit = is_hitting(map, ray_pos);
	}
	// printf("found wall at %d %d lol\n", ray_pos.x, ray_pos.y);
	if (side == 0)
		distance = (ray_pos.x - pos.x + (1.0f - step.x) / 2.0f) / dir.x;
	else
		distance = (ray_pos.y - pos.y + (1.0f - step.y) / 2.0f) / dir.y;
	if (side == 0)
		wall = pos.y + distance * dir.y;
	else
		wall = pos.x + distance * dir.x;
	result.hit = ft_vec2f(ray_pos.x, ray_pos.y);
	result.perpendicular_distance = distance;
	result.horizontal_ratio = wall - (int)wall;
	return (result);
}