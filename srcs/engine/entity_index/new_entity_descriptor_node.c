/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_entity_descriptor_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:48:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:26:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_index.h"
#include "engine/error.h"

t_entity_descriptor_node	*new_entity_descriptor_node(
								const t_static_string name,
								const t_static_string icon_path,
								t_constructor (*entity_constructor)())
{
	t_entity_descriptor_node	*ret;

	if (!(ret = (t_entity_descriptor_node*)
		malloc(sizeof(t_entity_descriptor_node))))
	{
		return (throw_error_str("new_entity_descriptor_node()",
			"failed to allocate entity descriptor node"));
	}
	init_list_head(&ret->node);
	ret->name = name;
	ret->icon_path = icon_path;
	ret->dnon_entity_constructor = entity_constructor;
	return (ret);
}
