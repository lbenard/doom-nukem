/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_descriptors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:45:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	init_block_descriptors(t_game *const self)
{
	module_add(&self->module, &self->blocks_list.blue_ice,
		block_descriptor('0', "Sandstone",
			"resources/textures/pack/block/sandstone.png"));
	module_add(&self->module, &self->blocks_list.white_wool,
		block_descriptor('1', "While wool",
			"resources/textures/white_wool.png"));
	module_add(&self->module, &self->blocks_list.acacia_log,
		block_descriptor('2', "Acacia log",
			"resources/textures/acacia_log.png"));
}