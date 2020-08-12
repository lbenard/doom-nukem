/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:06:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 15:47:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

void	crouch(t_player_entity *self)
{
	if (!self->is_jumping && !self->is_flying)
	{
		self->super.transform.position.z = -0.30;
		self->is_crouching = TRUE;
	}
}