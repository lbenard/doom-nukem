/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_from_texture_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:54:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/08 22:59:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_block_node	*block_from_texture_path(t_list_head *const self,
					const char *const path)
{
	t_list_head		*pos;
	t_block_node	*block;

	pos = self;
	while ((pos = pos->next) != self)
	{
		block = (t_block_node*)((t_u8*)pos
			- __builtin_offsetof(t_block_node, node));
		if (block->texture_path == path)
			return (block);
	}
	return (NULL);

}
