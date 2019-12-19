/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:22:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor_component_entity.h"
#include "game/entities/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/game.h"

t_result	init_editor_scene(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	if (init_scene(&self->super, "Editor", editor_scene_update,
		editor_scene_render) == ERROR)
	{
		return (throw_result_str("init_editor_scene()",
			"failed to init scene"));
	}
	module_add(&self->super.module, &self->vertex_texture,
		frame_from_file("resources/textures/editor-vertex-white.png"));
	module_add(&self->super.module, &self->vertex_selected_texture,
		frame_from_file("resources/textures/editor-vertex-red.png"));
	self->grid_ref = (t_editor_grid_component_entity*)entity_list_add_entity(
		&self->super.entities,
		editor_grid_component_entity(args->window_size));
	self->vertex_ref =
		(t_editor_vertex_component_entity*)entity_list_add_entity(
			&self->super.entities,
			editor_vertex_component_entity(
				ft_vec2f(.5f, .5f),
				&self->vertex_texture,
				&self->vertex_selected_texture));
	if (self->grid_ref)
		self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
			&self->super.entities,
			editor_camera_entity(self->grid_ref->unit_size));
	if (self->super.module.has_error)
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}