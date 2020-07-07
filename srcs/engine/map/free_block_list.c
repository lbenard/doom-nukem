/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_block_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:52:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 00:01:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	free_block_list(t_list_head *list)
{
	t_list_head		*pos;
	t_block_node	*node;

	pos = list;
	while ((pos = pos->next) != list)
	{
		node = (t_block_node*)((t_u8*)pos
			- __builtin_offsetof(t_block_node, node));
		destroy_block_node(node);
		free(node);
	}
}
