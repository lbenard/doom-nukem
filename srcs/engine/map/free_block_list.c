/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_block_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:52:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:27:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	free_block_list(t_list_head *list)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_block_node	*node;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		node = (t_block_node*)pos;
		free((char*)node->north_texture_name);
		free((char*)node->east_texture_name);
		free((char*)node->south_texture_name);
		free((char*)node->west_texture_name);
		free(node);
	}
}
