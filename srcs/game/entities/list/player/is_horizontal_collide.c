/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_horizontal_collide.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:08:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:08:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_bool	is_horizontal_collide(t_corners box)
{
	if (box.ne && box.no && !box.se && !box.so)
		return (TRUE);
	else if (!box.ne && !box.no && box.se && box.so)
		return (TRUE);
	else
		return (FALSE);
}
