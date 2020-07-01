/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:33:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 20:12:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"
#include "maths/maths.h"

#include <stdio.h>

static t_bool	is_position_free(t_block_component_entity *const self)
{
	const t_list_head			*pos;
	const t_component_entity	*component;

	pos = &self->block_list->list;
	while ((pos = pos->next) != &self->block_list->list)
	{
		component = (t_component_entity*)((t_entity_node*)pos)->entity;
		if (component == (t_component_entity*)self)
			continue ;
		if (ft_fabs(component->super.transform.position.x
				- self->super.super.transform.position.x) < 0.001f
			&& ft_fabs(component->super.transform.position.y
				- self->super.super.transform.position.y) < 0.001f)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

void			block_component_entity_update(
					t_block_component_entity *const self)
{
	if (self->super.is_moved && !self->was_not_moved)
	{
		self->was_not_moved = TRUE;
		self->pos_before_move = self->super.super.transform.position;
	}
	if (self->super.is_moved == FALSE)
	{
		self->was_not_moved = FALSE;
		if (self->super.super.transform.position.x < 0.0f)
			self->super.super.transform.position.x = (int)(self->super.super.transform.position.x - 0.5f);
		else
			self->super.super.transform.position.x = (int)(self->super.super.transform.position.x + 0.5f);
		if (self->super.super.transform.position.y < 0.0f)
			self->super.super.transform.position.y = (int)(self->super.super.transform.position.y - 0.5f);
		else
			self->super.super.transform.position.y = (int)(self->super.super.transform.position.y + 0.5f);
		if (!is_position_free(self))
			self->super.super.transform.position = self->pos_before_move;
	}
}
