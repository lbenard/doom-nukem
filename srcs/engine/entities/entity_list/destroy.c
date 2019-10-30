/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:53:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_list.h"
#include "engine/entity_node.h"

void	destroy_entity_list(t_entity_list *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_entity_node	*entity;

	pos = &self->list;
	next = pos->next;
	while ((pos = next) != &self->list)
	{
		next = next->next;
		entity = (t_entity_node*)pos;
		entity->free_fn(entity->entity);
		free(entity);
	}
}
