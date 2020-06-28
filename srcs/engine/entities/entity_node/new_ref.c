/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ref.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 06:45:21 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:25:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_node.h"

t_entity_node	*new_entity_node_ref(t_entity *const entity)
{
	t_entity_node	*ret;

	if (!entity)
		return (NULL);
	if (!(ret = (t_entity_node*)malloc(sizeof(t_entity_node))))
		return (NULL);
	init_list_head(&ret->node);
	ret->entity = entity;
	ret->is_ref = TRUE;
	ret->free_fn = NULL;
	return (ret);
}
