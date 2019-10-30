/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:14:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:23:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_node.h"
#include "containers/list.h"

t_entity_node	*new_entity_node(t_classic_entity *const entity,
					void (*free_fn)())
{
	t_entity_node	*ret;

	if (!entity)
		return (NULL);
	if (!(ret = (t_entity_node*)malloc(sizeof(t_entity_node))))
		return (NULL);
	*(t_classic_entity**)&ret->entity = entity;
	init_list_head(&ret->node);
	ret->free_fn = free_fn;
	return (ret);
}
