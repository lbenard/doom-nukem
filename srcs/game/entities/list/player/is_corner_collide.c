/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_corner_collide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:13:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:16:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_bool	is_corner_collide(const t_corners box_corner, t_vec3f *const vel)
{
	if (box_corner.ne + box_corner.no + box_corner.se + box_corner.so == 1)
	{
		if (box_corner.ne)
			*vel = north_east_rebound(*vel);
		if (box_corner.se)
			*vel = south_east_rebound(*vel);
		if (box_corner.so)
			*vel = south_west_rebound(*vel);
		if (box_corner.no)
			*vel = north_west_rebound(*vel);
		return (TRUE);
	}
	return (FALSE);
}
