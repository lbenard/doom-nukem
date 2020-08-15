/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:33:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "engine/error.h"

t_result	init_editor_camera_entity(t_editor_camera_entity *const self,
				const t_editor_camera_entity_args *const args)
{
	init_entity_default(&self->super,
		entity_vtable(editor_camera_entity_update));
	module_add(&self->super.module, &self->event_handler, event_handler(self));
	event_handler_add_sub_handler(&args->editor->input_manager,
		&self->event_handler);
	event_handler_add_callback(&self->event_handler,
		new_editor_camera_zoom_event(args->fb));
	if (self->super.module.has_error || self->event_handler.module.has_error)
	{
		destroy_editor_camera_entity(self);
		return (throw_result_str("init_editor_camera_entity()",
			"failed to init entity module"));
	}
	self->up = input_get_id(&game_singleton()->input, "EditorCameraUp");
	self->right = input_get_id(&game_singleton()->input, "EditorCameraRight");
	self->down = input_get_id(&game_singleton()->input, "EditorCameraDown");
	self->left = input_get_id(&game_singleton()->input, "EditorCameraLeft");
	self->dezoom = input_get_id(&game_singleton()->input, "EditorCameraDezoom");
	self->zoom = input_get_id(&game_singleton()->input, "EditorCameraZoom");
	self->grid_unit = args->grid_unit;
	return (OK);
}
