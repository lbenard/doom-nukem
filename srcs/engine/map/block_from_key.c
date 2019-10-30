/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_from_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:10:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:27:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_block_node	*block_from_key(t_list_head *const self, const char key)
{
	t_list_head	*pos;
	t_list_head	*next;

	pos = self;
	next = pos->next;
	while ((pos = next) != self)
	{
		next = next->next;
		if (((t_block_node*)pos)->key == key)
			return ((t_block_node*)pos);
	}
	return (NULL);
}
