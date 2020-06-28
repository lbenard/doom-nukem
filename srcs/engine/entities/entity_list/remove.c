/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 08:44:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:25:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/entity_node.h"

void	entity_list_remove(t_entity_list *const self,
			const t_entity *const entity_ptr)
{
	t_list_head		*pos;
	t_entity_node	*node;

	pos = &self->list;
	while ((pos = pos->next) != &self->list)
	{
		node = (t_entity_node*)pos;
		if (node->entity == entity_ptr)
		{
			list_del_entry(&node->node);
			free_entity_node(node);
			break ;
		}
	}
}
