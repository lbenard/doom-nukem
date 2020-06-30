/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 18:26:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "engine/delta.h"

#include <stdio.h>

void	new_editor_scene_update(t_new_editor_scene *const self)
{
	entity_list_update(&self->super.entities);
	update_radio_group(&self->hud.tools);
	update_radio_group(&self->hud.create);
	update_radio_group(&self->hud.blocks);
	// update_radio_group(&self->hud.entities);

	radio_group_set_active(&self->hud.tools, TRUE);
	radio_group_set_active(&self->hud.create,
		self->hud.tools_group.create_ref->is_checked);
	radio_group_set_active(&self->hud.blocks,
		self->hud.create_group.show_blocks_ref->is_checked
		&& self->hud.create_group.show_blocks_ref->is_active);
	// radio_group_set_active(&self->hud.entities,
	// 	self->hud.create_group.show_entities_ref->is_checked
	// 	&& self->hud.create_group.show_entities_ref->is_active);
	
	printf("block hover: %d\n",
		self->hud.create_group.show_blocks_ref->is_hovered);
	printf("ice hover: %d\n",
		self->hud.blocks_group.blue_ice->super.super.is_hovered);
	printf("wool hover: %d\n",
		self->hud.blocks_group.white_wool->super.super.is_hovered);
	printf("acacia hover: %d\n",
		self->hud.blocks_group.acacia_log->super.super.is_hovered);
	// printf("blocks: %lu\n", list_size(&self->blocks));
	// printf("entities: %lu\n", list_size(&self->entities));
	// printf("cursor is checked: %d\n", self->hud.tools_group.cursor_ref->is_checked);
	// printf("create is checked: %d\n", self->hud.tools_group.create_ref->is_checked);
}