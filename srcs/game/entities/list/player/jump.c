/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:35:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/20 18:39:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include <math.h>

void	jump(t_player_entity *self)
{
	if (self->is_jumping == FALSE && !self->is_flying)
	{
		self->super.transform.direction.z += 0.114f;
		self->just_jump = TRUE;
		self->is_jumping = TRUE;
	}
}
