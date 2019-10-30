/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vertical_collide.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:08:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:08:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_bool	is_vertical_collide(t_corners box)
{
	if (box.ne && box.se && !box.no && !box.so)
		return (TRUE);
	else if (!box.ne && !box.se && box.no && box.so)
		return (TRUE);
	else
		return (FALSE);
}
