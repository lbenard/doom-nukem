/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:33:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 03:53:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"

void	block_component_entity_update(t_block_component_entity *const self)
{
	if (self->super.is_moved == FALSE)
	{
		if (self->super.super.transform.position.x < 0.0f)
			self->super.super.transform.position.x = (int)(self->super.super.transform.position.x - 0.45f);
		else
			self->super.super.transform.position.x = (int)self->super.super.transform.position.x;
		if (self->super.super.transform.position.y < 0.0f)
			self->super.super.transform.position.y = (int)(self->super.super.transform.position.y - 0.45f);
		else
			self->super.super.transform.position.y = (int)self->super.super.transform.position.y;
	}
}
