/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/29 21:26:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor_component_entity.h"
#include "game/entities/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/game.h"

static void	add_modules(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	module_add(&self->super.module, &self->components, entity_list());
	module_add(&self->super.module, &self->vertex_texture,
		frame_from_file("resources/textures/editor-vertex-white.png"));
	module_add(&self->super.module, &self->vertex_selected_texture,
		frame_from_file("resources/textures/editor-vertex-red.png"));
	module_add(&self->super.module, &self->title,
		text("haxorville.png", args->screen->size));
	if (!self->super.module.has_error)
		text_set_ref(&self->title,
			static_string_as_ref(ft_static_string("EDITEUR BADASS")));
	if (!self->super.module.has_error)
	{
		frame_fill_blend(&self->title.font.raster, ft_rgba(255, 255, 255, 255),
			blend_colorize);
		text_render(&self->title, ft_text_settings(ft_isize(0, 0), 42));
	}
}

static void	add_entities(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	self->grid_ref =
		(t_editor_grid_component_entity*)entity_list_add_entity_ref(
			&self->components,
			entity_list_add_entity(
				&self->super.entities,
				editor_grid_component_entity(args->screen->size)));
	self->vertex_ref =
		(t_editor_vertex_component_entity*)entity_list_add_entity_ref(
			&self->components,
			entity_list_add_entity(&self->super.entities,
				editor_vertex_component_entity(
					ft_vec2f(.5f, .5f),
					&self->vertex_texture,
					&self->vertex_selected_texture)));
	(t_editor_vertex_component_entity*)entity_list_add_entity_ref(
		&self->components,
		entity_list_add_entity(&self->super.entities,
			editor_vertex_component_entity(
				ft_vec2f(-.5f, .5f),
				&self->vertex_texture,
				&self->vertex_selected_texture)));
	if (self->grid_ref)
		self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
			&self->super.entities,
			editor_camera_entity(self->grid_ref->unit_size));
}

t_result	init_editor_scene(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	if (init_scene(&self->super, "Editor", editor_scene_update,
		editor_scene_render) == ERROR)
	{
		return (throw_result_str("init_editor_scene()",
			"failed to init scene"));
	}
	add_modules(self, args);
	add_entities(self, args);
	event_handler_add_callback(&self->super.input_manager,
		new_component_movement_event());
	self->screen_ref = args->screen;
	self->selected_component = NULL;
	if (self->super.module.has_error)
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}