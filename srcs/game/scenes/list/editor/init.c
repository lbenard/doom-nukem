/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 01:24:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "game/scenes/editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"
#include "game/game.h"
#include "engine/map.h"

static void	floor_ceiling(t_editor_scene *const self)
{
	module_add(&self->super.module, &self->set_floor,
		text("resources/fonts/haxorville.bmp",
			ft_usize(5 * ft_strlen("Set floor"), 9)));
	module_add(&self->super.module, &self->set_ceiling,
		text("resources/fonts/haxorville.bmp",
			ft_usize(5 * ft_strlen("Set ceiling"), 9)));
	module_add(&self->super.module, &self->set_floor_key,
		frame_from_file("resources/sprites/set-floor-key.bmp"));
	module_add(&self->super.module, &self->set_ceiling_key,
		frame_from_file("resources/sprites/set-ceiling-key.bmp"));
	if (!self->super.module.has_error)
	{
		text_set_ref(&self->set_floor,
			static_string_as_ref(ft_static_string("Set floor")));
		text_set_ref(&self->set_ceiling,
			static_string_as_ref(ft_static_string("Set ceiling")));
		text_render(&self->set_floor, ft_text_settings(ft_isize(0, 0), 9));
		text_render(&self->set_ceiling, ft_text_settings(ft_isize(0, 0), 9));
		frame_fill_blend(&self->set_floor.target, ft_rgba(255, 255, 255, 255),
			blend_colorize);
		frame_fill_blend(&self->set_ceiling.target, ft_rgba(255, 255, 255, 255),
			blend_colorize);
	}
}

static void	add_modules(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	module_add(&self->super.module,
		&self->editor_view,
		frame(ft_usize(args->screen->size.x - 400, args->screen->size.y),
			ft_rgba(64, 0, 0, 255)));
	module_add(&self->super.module,
		&self->editor_background,
		frame_from_file("resources/textures/bob.bmp"));
	module_add(&self->super.module, &self->components, entity_list());
	module_add(&self->super.module, &self->blocks, entity_list());
	module_add(&self->super.module, &self->entities, entity_list());
}

static void	set_inputs(t_editor_scene *const self)
{
	self->set_floor_input = input_get_id(&game_singleton()->input,
		"EditorSetFloor");
	self->set_ceiling_input = input_get_id(&game_singleton()->input,
		"EditorSetCeiling");
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
	self->selected_component_ref = NULL;
	self->path = args->path;
	self->screen_ref = args->screen;
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self, args, game_singleton());
	fill_from_map(self, args->path);
	init_event_handler_callback(self);
	set_inputs(self);
	floor_ceiling(self);
	if (self->super.module.has_error == TRUE
		|| self->super.entities.module.has_error == TRUE)
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	init_radio_groups(self);
	return (OK);
}
