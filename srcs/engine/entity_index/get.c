/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:36:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:26:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_index.h"
#include "ft/str.h"

t_constructor	(*entity_index_get(t_entity_index *const self,
					const char *name))()
{
	t_list_head					*pos;
	t_entity_descriptor_node	*node;

	pos = &self->descriptors;
	while ((pos = pos->next) != &self->descriptors)
	{
		node = (t_entity_descriptor_node*)pos;
		if (ft_strcmp(name, node->name.str) == 0)
			return (node->dnon_entity_constructor);
	}
	return (NULL);
}
