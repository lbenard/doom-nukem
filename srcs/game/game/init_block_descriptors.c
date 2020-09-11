/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_descriptors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:45:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 09:31:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

static void	block(t_block_descriptor *const descriptor,
				const char id,
				const char *name,
				const char *path)
{
	module_add(&game_singleton()->module, descriptor,
		block_descriptor(id, name, path));
}

static void	add_blocks(t_game *const self)
{
	block(&self->blocks_list.sandstone, '0', "Sandstone",
		"resources/textures/blocks/sandstone.bmp");
	block(&self->blocks_list.metallic_wall, '1', "Metallic wall",
		"resources/textures/blocks/metallic-wall.bmp");
	block(&self->blocks_list.metallic_crate, '2', "Metallic crate",
		"resources/textures/blocks/metallic-crate.bmp");
	block(&self->blocks_list.metallic_door, '3', "Metallic door",
		"resources/textures/blocks/metallic-door.bmp");
	block(&self->blocks_list.metallic_light_tile, '4', "Metallic light tile",
		"resources/textures/blocks/metallic-light-tile.bmp");
	block(&self->blocks_list.metallic_dark_tile, '5', "Metallic dark tile",
		"resources/textures/blocks/metallic-dark-tile.bmp");
	block(&self->blocks_list.andesite, 'I', "Andesite",
		"resources/textures/blocks/andesite.bmp");
	block(&self->blocks_list.coarse_dirt, 'J', "Coarse dirt",
		"resources/textures/blocks/coarse-dirt.bmp");
	block(&self->blocks_list.wood_screen, 'K', "Wood screen",
		"resources/textures/blocks/wood-screen.bmp");
	block(&self->blocks_list.red_brick, 'L', "Red brick",
		"resources/textures/blocks/red-brick.bmp");
	block(&self->blocks_list.granite, 'M', "Red brick",
		"resources/textures/blocks/granite.bmp");
}

static void	add_button_door(t_game *const self)
{
	block(&self->blocks_list.metallic_red_button, '6', "Metallic red button",
		"resources/textures/blocks/metallic-red-button.bmp");
	block(&self->blocks_list.metallic_green_button, '7',
		"Metallic green button",
		"resources/textures/blocks/metallic-green-button.bmp");
	block(&self->blocks_list.metallic_blue_button, '8', "Metallic blue button",
		"resources/textures/blocks/metallic-blue-button.bmp");
	block(&self->blocks_list.metallic_red_door, '9', "Metallic red door",
		"resources/textures/blocks/metallic-red-door.bmp");
	block(&self->blocks_list.metallic_green_door, 'A', "Metallic green door",
		"resources/textures/blocks/metallic-green-door.bmp");
	block(&self->blocks_list.metallic_blue_door, 'B', "Metallic blue door",
		"resources/textures/blocks/metallic-blue-door.bmp");
}

static void	add_glasses(t_game *const self)
{
	block(&self->blocks_list.white_glass, 'D', "White glass",
		"resources/textures/blocks/white-glass.bmp");
	block(&self->blocks_list.black_glass, 'E', "Black glass",
		"resources/textures/blocks/black-glass.bmp");
	block(&self->blocks_list.red_glass, 'F', "Red glass",
		"resources/textures/blocks/red-glass.bmp");
	block(&self->blocks_list.green_glass, 'G', "Green glass",
		"resources/textures/blocks/green-glass.bmp");
	block(&self->blocks_list.blue_glass, 'H', "Blue glass",
		"resources/textures/blocks/blue-glass.bmp");
}

void		init_block_descriptors(t_game *const self)
{
	add_blocks(self);
	add_button_door(self);
	block(&self->blocks_list.ending, 'C', "Ending",
		"resources/textures/blocks/metallic-ending-button.bmp");
	add_glasses(self);
}
