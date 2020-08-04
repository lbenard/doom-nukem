/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:44:44 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 18:50:46 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/entity_node.h"

void	entity_list_update(t_entity_list *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity_node	*node;

	pos = &self->list;
	next = pos->next;
	while ((pos = next) != &self->list)
	{
		next = pos->next;
		node = (t_entity_node*)pos;
		node->entity->vtable.update(node->entity);
	}
}
