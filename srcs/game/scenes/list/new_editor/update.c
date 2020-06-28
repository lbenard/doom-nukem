/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 18:46:35 by lbenard          ###   ########.fr       */
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
	self->hud.create_group.show_blocks_ref->is_active =
		self->hud.tools_group.create_ref->is_checked;
	self->hud.create_group.show_entities_ref->is_active =
		self->hud.tools_group.create_ref->is_checked;
	// printf("blocks: %lu\n", list_size(&self->blocks));
	// printf("entities: %lu\n", list_size(&self->entities));
	// printf("cursor is checked: %d\n", self->hud.tools_group.cursor_ref->is_checked);
	// printf("create is checked: %d\n", self->hud.tools_group.create_ref->is_checked);
}