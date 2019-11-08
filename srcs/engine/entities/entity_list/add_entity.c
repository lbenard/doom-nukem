/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:46:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:53:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_list.h"
#include "engine/entity_node.h"
#include "engine/error.h"

t_classic_entity	*entity_list_add_entity(t_entity_list *const self,
						const t_constructor constructor)
{
	t_classic_entity	*new_entity;
	t_entity_node		*node;

	if (self->module.has_error == TRUE)
		return (NULL);
	if (!(new_entity = (t_classic_entity*)static_module_allocate(constructor)))
	{
		self->module.has_error = TRUE;
		return (NULL);
	}
	if (!(node = new_entity_node(new_entity, constructor.destructor_fn)))
	{
		constructor.destructor_fn(new_entity);
		free(new_entity);
		self->module.has_error = TRUE;
		return (NULL);
	}
	list_add_entry(&node->node, &self->list);
	return (new_entity);
}
