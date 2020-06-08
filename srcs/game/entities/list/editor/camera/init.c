/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:33:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 02:03:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "engine/error.h"

t_result	init_editor_camera_entity(t_editor_camera_entity *const self,
				const t_editor_camera_entity_args *const args)
{
	init_entity_default(&self->super,
		entity_vtable(editor_camera_entity_update));
	module_add(&self->super.module, &self->event_handler, event_handler(self));
	event_handler_add_sub_handler(&game_singleton()->event_handler,
		&self->event_handler);
	event_handler_add_callback(&self->event_handler,
		new_editor_camera_zoom_event());
	if (self->super.module.has_error || self->event_handler.module.has_error)
	{
		destroy_editor_camera_entity(self);
		return (throw_result_str("init_editor_camera_entity()",
			"failed to init entity module"));
	}
	self->up = input_get_id(&game_singleton()->input, "CameraUp");
	self->right = input_get_id(&game_singleton()->input, "CameraRight");
	self->down = input_get_id(&game_singleton()->input, "CameraDown");
	self->left = input_get_id(&game_singleton()->input, "CameraLeft");
	self->grid_unit = args->grid_unit;
	return (OK);
}