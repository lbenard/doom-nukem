/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:44:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 21:17:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/entity_node.h"

void	entity_list_update(t_entity_list *const self)
{
	t_list_head		*pos;
	t_entity_node	*node;

	pos = &self->list;
	while ((pos = pos->next) != &self->list)
	{
		node = (t_entity_node*)pos;
		node->entity->vtable.update(node->entity);
	}
}
