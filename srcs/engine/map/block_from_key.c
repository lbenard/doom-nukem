/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_from_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:10:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "game/game.h"

t_block_descriptor	*block_from_key(const char key)
{
	t_block_descriptor	*blocks;
	size_t				block_amount;
	size_t				i;

	blocks = (t_block_descriptor*)&game_singleton()->blocks_list;
	block_amount = sizeof(game_singleton()->blocks_list)
		/ sizeof(t_block_descriptor);
	i = 0;
	while (i < block_amount)
	{
		if (blocks[i].id == key)
			return (&blocks[i]);
		i++;
	}
	return (NULL);
}
