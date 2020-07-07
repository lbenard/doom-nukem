/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_from_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:10:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/06 23:49:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_block_node	*block_from_key(t_list_head *const self, const char key)
{
	t_list_head		*pos;
	t_block_node	*block;

	pos = self;
	while ((pos = pos->next) != self)
	{
		block = (t_block_node*)((t_u8*)pos
			- __builtin_offsetof(t_block_node, node));
		if (block->key == key)
			return (block);
	}
	return (NULL);
}
