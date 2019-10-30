/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:46:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:23:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/entity_node.h"
#include "engine/error.h"

t_classic_entity	*entity_list_add_entity(t_entity_list *const self,
						const t_hmodule_factory factory)
{
	t_classic_entity	*new_entity;
	t_entity_node		*node;

	if (self->module.has_error == TRUE)
		return (NULL);
	if (!(new_entity = (t_classic_entity*)
		factory.descriptor.new_fn(factory.args)))
	{
		self->module.has_error = TRUE;
		return (NULL);
	}
	if (!(node = new_entity_node(new_entity, factory.descriptor.free_fn)))
	{
		factory.descriptor.free_fn(new_entity);
		self->module.has_error = TRUE;
		return (NULL);
	}
	list_add_entry(&node->node, &self->list);
	return (new_entity);
}
