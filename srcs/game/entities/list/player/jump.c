/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:35:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 02:08:08 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include <math.h>
#include <stdio.h>

void	jump(t_player_entity *self)
{
	float		weight;
	const float	g = 5.0f;

	weight = 0.07f;
	if (self->is_jumping == FALSE)
	{
		self->super.transform.direction.z = 0.114f;
		self->is_jumping = TRUE;
	}
	else
	{
		self->super.transform.direction.z -= ((weight * g) * (1.0f / 30.0f));
		self->super.transform.position.z += self->super.transform.direction.z;
		if (self->super.transform.position.z <= 0.0f)
		{
			self->super.transform.position.z = 0;
			self->is_jumping = FALSE;
			self->just_jump = FALSE;
		}
	}
}
