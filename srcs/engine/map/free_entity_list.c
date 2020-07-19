/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entity_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:23:13 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 01:25:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	free_entity_list(t_list_head *list)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_map_entity_node	*node;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = pos->next;
		node = (t_map_entity_node*)((t_u8*)pos
			- __builtin_offsetof(t_map_entity_node, node));
		destroy_map_entity_node(node);
		free(node);
	}
}