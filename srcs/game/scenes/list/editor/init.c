/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:07:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/ghost_segment_component_entity.h"
#include "engine/error.h"
#include "engine/game.h"

static void	add_modules(t_editor_scene *const self)
{
	module_add(&self->super.module, &self->components, entity_list());
	module_add(&self->super.module, &self->vertex_texture,
		frame_from_file("resources/textures/editor-vertex-white.png"));
	module_add(&self->super.module, &self->vertex_selected_texture,
		frame_from_file("resources/textures/editor-vertex-red.png"));
}

static void	add_entities(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	t_grid_component_entity	*grid_ref;

	grid_ref = (t_grid_component_entity*) entity_list_add_entity_ref(
		&self->components,
		entity_list_add_entity(
			&self->super.entities,
			grid_component_entity(args->screen->size)));

	size_t	i = 0;
	while (i < 10)
	{
		size_t	y = 0;
		while (y < 100)
		{
			t_vertex_component_entity *vertex =
				(t_vertex_component_entity*)entity_list_add_entity_ref(
					&self->components,
					entity_list_add_entity(
						&self->super.entities,
						vertex_component_entity(
							ft_vec2f(.1f * i, .1f * y),
							&self->vertex_texture,
							&self->vertex_selected_texture)));
			list_add_entry(&vertex->super.selection_node, &self->selected_components);
			y++;
		}
		i++;
	}
	if (!self->super.module.has_error)
		self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
			&self->super.entities,
			editor_camera_entity(grid_ref->unit_size));
	self->hud.cursor_ref = (t_checkbox_entity*)entity_list_add_entity(
		&self->super.entities,
		checkbox_entity("resources/buttons/editor-cursor.png",
			"resources/buttons/editor-cursor-hover.png",
			"resources/buttons/editor-cursor-click.png",
			args->screen));
	self->hud.create_ref = (t_checkbox_entity*)entity_list_add_entity(
		&self->super.entities,
		checkbox_entity("resources/buttons/editor-create.png",
			"resources/buttons/editor-create.png",
			"resources/buttons/editor-create.png",
			args->screen));
	if (self->hud.cursor_ref && self->hud.create_ref)
	{
		self->hud.cursor_ref->super.transform.position = ft_vec3f(22.0f, 25.0f, 0.0f);
		self->hud.cursor_ref->super.transform.scale = ft_vec3f(2.0f, 2.0f, 1.0f);
		self->hud.create_ref->super.transform.position = ft_vec3f(64.0f, 25.0f, 0.0f);
		self->hud.create_ref->super.transform.scale = ft_vec3f(2.0f, 2.0f, 1.0f);
	}
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
	init_list_head(&self->selected_components);
	add_modules(self);
	add_entities(self, args);
	event_handler_add_callback(&self->super.input_manager,
		new_component_cursor_event());
	event_handler_add_callback(&self->super.input_manager,
		new_component_create_event());
	self->mode = CURSOR;
	self->screen_ref = args->screen;
	if (self->super.module.has_error)
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}