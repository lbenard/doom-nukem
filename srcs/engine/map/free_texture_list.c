/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:51:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 00:02:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	free_texture_list(t_list_head *list)
{
	t_list_head		*pos;
	t_texture_node	*node;

	pos = list;
	while ((pos = pos->next) != list)
	{
		node = (t_texture_node*)((t_u8*)pos
			- __builtin_offsetof(t_texture_node, node));
		destroy_texture_node(node);
		free(node);
	}
}
