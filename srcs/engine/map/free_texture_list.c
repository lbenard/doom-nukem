/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:51:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:27:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	free_texture_list(t_list_head *list)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_texture_node	*node;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		node = (t_texture_node*)pos;
		free((char*)node->key);
		sfImage_destroy(node->image);
		free(node);
	}
}
