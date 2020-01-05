/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity_ref.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:38:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 03:19:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_list.h"
#include "engine/entity_node.h"
#include "engine/error.h"

t_entity	*entity_list_add_entity_ref(t_entity_list *const self,
				t_entity *const entity)
{
	t_entity_node	*node;

	if (self->module.has_error == TRUE || !entity)
		return (NULL);
	if (!(node = new_entity_node(entity, NULL)))
	{
		self->module.has_error = TRUE;
		return (NULL);
	}
	list_add_entry(&node->node, &self->list);
	return (entity);
}
