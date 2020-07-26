/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_descriptors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:45:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 20:28:21 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	init_block_descriptors(t_game *const self)
{
	module_add(&self->module, &self->blocks_list.blue_ice,
		block_descriptor('0', "Sandstone",
			"resources/textures/pack/block/sandstone.bmp"));
	module_add(&self->module, &self->blocks_list.white_wool,
		block_descriptor('1', "While wool",
			"resources/textures/white_wool.bmp"));
	module_add(&self->module, &self->blocks_list.acacia_log,
		block_descriptor('2', "Acacia log",
			"resources/textures/acacia_log.png"));
}