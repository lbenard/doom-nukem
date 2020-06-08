/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:14:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/21 06:45:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_node.h"
#include "containers/list.h"

t_entity_node	*new_entity_node(t_entity *const entity,
					void (*free_fn)())
{
	t_entity_node	*ret;

	if (!entity)
		return (NULL);
	if (!(ret = (t_entity_node*)malloc(sizeof(t_entity_node))))
		return (NULL);
	init_list_head(&ret->node);
	ret->entity = entity;
	ret->is_ref = FALSE;
	ret->free_fn = free_fn;
	return (ret);
}
