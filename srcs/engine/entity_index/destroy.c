/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:52:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 23:23:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_index.h"

static void	destroy_descriptors(t_list_head *const descriptors)
{
	t_list_head					*pos;
	t_list_head					*next;
	t_entity_descriptor_node	*node;

	pos = descriptors;
	next = pos->next;
	while ((pos = next) != descriptors)
	{
		next = pos->next;
		node = (t_entity_descriptor_node*)pos;
		free(node);
	}
}

void		destroy_entity_index(t_entity_index *const self)
{
	destroy_descriptors(&self->descriptors);
	destroy_module(&self->module);
}