/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:57:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/09 21:03:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "game/entities/weapon_entity.h"

void	weapon_entity_update(t_weapon_entity *const self)
{
	sprite_entity_update(&self->super);
	self->just_shooted = FALSE;
	self->just_reloaded = FALSE;
	if (self->reloading)
	{
		self->reloading = FALSE;
		self->just_reloaded = TRUE;
	}
}
