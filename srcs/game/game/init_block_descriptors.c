/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_descriptors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:45:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 20:51:01 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	init_block_descriptors(t_game *const self)
{
	module_add(&self->module, &self->blocks_list.sandstone,
		block_descriptor('0', "Sandstone",
			"resources/textures/sandstone.png"));
	module_add(&self->module, &self->blocks_list.metallic_wall,
		block_descriptor('1', "Metallic wall",
			"resources/textures/metallic-wall.png"));
	module_add(&self->module, &self->blocks_list.metallic_crate,
		block_descriptor('2', "Metallic crate",
			"resources/textures/metallic-crate.png"));
	module_add(&self->module, &self->blocks_list.metallic_door,
		block_descriptor('3', "Metallic door",
			"resources/textures/metallic-door.png"));
	module_add(&self->module, &self->blocks_list.metallic_light_tile,
		block_descriptor('4', "Metallic light tile",
			"resources/textures/metallic-light-tile.png"));
	module_add(&self->module, &self->blocks_list.metallic_dark_tile,
		block_descriptor('5', "Metallic dark tile",
			"resources/textures/metallic-dark-tile.png"));
	module_add(&self->module, &self->blocks_list.metallic_red_button,
		block_descriptor('6', "Metallic red button",
			"resources/textures/metallic-red-button.png"));
	module_add(&self->module, &self->blocks_list.metallic_green_button,
		block_descriptor('7', "Metallic green button",
			"resources/textures/metallic-green-button.png"));
	module_add(&self->module, &self->blocks_list.metallic_blue_button,
		block_descriptor('8', "Metallic blue button",
			"resources/textures/metallic-blue-button.png"));
	module_add(&self->module, &self->blocks_list.metallic_red_door,
		block_descriptor('9', "Metallic red door",
			"resources/textures/metallic-red-door.png"));
	module_add(&self->module, &self->blocks_list.metallic_green_door,
		block_descriptor('A', "Metallic green door",
			"resources/textures/metallic-green-door.png"));
	module_add(&self->module, &self->blocks_list.metallic_blue_door,
		block_descriptor('B', "Metallic blue door",
			"resources/textures/metallic-blue-door.png"));
}