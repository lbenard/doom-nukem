/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:06:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:42:25 by lbenard          ###   ########.fr       */
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

t_u8			progress(const t_map *const map, t_raycast *const raycast)
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

	init_raycast(&raycast, pos, dir);
	return (ft_ray(&raycast, progress(map, &raycast)));
}
