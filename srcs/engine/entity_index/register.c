/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:26:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_index.h"
#include "engine/error.h"

t_result	entity_index_register(t_entity_index *const self,
				t_entity_descriptor_node *const descriptor)
{
	if (!descriptor)
	{
		self->module.has_error = TRUE;
		return (throw_result_str("entity_index_register()",
			"descriptor isn't valid"));
	}
	list_add_entry(&descriptor->node, &self->descriptors);
	return (OK);
}
