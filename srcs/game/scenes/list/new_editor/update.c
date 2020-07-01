/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 03:49:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "engine/delta.h"

void	new_editor_scene_update(t_new_editor_scene *const self)
{
	static t_vec2f	old_pos = (t_vec2f){0.0f, 0.0f};
	t_vec2f			new_pos;

	entity_list_update(&self->super.entities);
	new_pos = editor_camera_entity_screen_to_editor_camera_pos(
		self->camera_ref,
		&self->screen_ref->frame, window_get_mouse_pos(self->screen_ref));
	if (self->selected_component_ref)
	{
		self->selected_component_ref->super.transform.position.x
			+= new_pos.x - old_pos.x;
		self->selected_component_ref->super.transform.position.y
			+= new_pos.y - old_pos.y;
	}
	old_pos = new_pos;
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
}