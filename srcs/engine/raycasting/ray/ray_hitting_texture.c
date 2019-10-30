/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hitting_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 07:09:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 04:11:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

const t_image	*ray_hitting_texture(const t_map *const map,
					const t_vec2f pos,
					const t_direction direction,
					const t_vec2f shift)
{
	t_wall	*wall;
	t_vec2f	collision;

	collision = pos;
	collision.x += shift.x;
	collision.y += shift.y;
	wall = &map->map[(int)collision.x + (int)collision.y * map->size.x];
	if (direction == NORTH && wall->north_texture_ref)
		return (wall->north_texture_ref);
	if (direction == EAST && wall->east_texture_ref)
		return (wall->east_texture_ref);
	if (direction == SOUTH && wall->south_texture_ref)
		return (wall->south_texture_ref);
	if (direction == WEST && wall->west_texture_ref)
		return (wall->west_texture_ref);
	return (NULL);
}
