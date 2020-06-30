/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 04:07:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/ghost_segment_component_entity.h"
#include "engine/error.h"
#include "engine/game.h"

static void	add_modules(t_new_editor_scene *const self,
				const t_new_editor_scene_args *const args)
{
	module_add(&self->super.module, &self->dinosaur,
		frame_from_bmp("dinosaur.bmp"));
	module_add(&self->super.module,
		&self->editor_view,
		frame(ft_usize(args->screen->size.x - 400, args->screen->size.y),
			ft_rgba(64, 0, 0, 255)));
	module_add(&self->super.module,
		&self->editor_background,
		frame_from_file("resources/textures/bob.jpg"));
}

static void	add_entities(t_new_editor_scene *const self,
				const t_new_editor_scene_args *const args)
{
	self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
		&self->super.entities,
		editor_camera_entity(self->editor_view.size.y * 0.2f,
			&self->editor_view));
	self->grid_ref = (t_grid_component_entity*)entity_list_add_entity(
		&self->super.entities,
		grid_component_entity(self->editor_view.size));
	self->hud.tools_group.cursor_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor-cursor.png", ft_checkbox_position_pos(
		ft_vec3f(self->editor_view.size.x + 30.0f, 30.0f, 0.0f)), args->screen);
	self->hud.tools_group.create_ref = create_checkbox_relative(
		&self->super.entities, "editor-create.png",
		ft_checkbox_position(self->hud.tools_group.cursor_ref, RIGHT_TO, 50.0f),
		args->screen);
	self->hud.create_group.show_blocks_ref = create_checkbox_relative(
		&self->super.entities, "editor-block.png", ft_checkbox_position(
		self->hud.tools_group.create_ref, BELOW, 50.0f), args->screen);
	self->hud.create_group.show_entities_ref = create_checkbox_relative(
		&self->super.entities, "editor-entity.png", ft_checkbox_position(
		self->hud.create_group.show_blocks_ref, RIGHT_TO, 50.0f), args->screen);
	self->hud.blocks_group.blue_ice = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		"resources/textures/blue_ice.png", args->screen);
	self->hud.blocks_group.white_wool = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		"resources/textures/white_wool.png", args->screen);
	self->hud.blocks_group.acacia_log = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		"resources/textures/acacia_log.png", args->screen);
}

t_result	init_new_editor_scene(t_new_editor_scene *const self,
				const t_new_editor_scene_args *const args)
{
	if (init_scene(&self->super, "Editor", new_editor_scene_update,
		new_editor_scene_render) == ERROR)
	{
		return (throw_result_str("init_new_editor_scene()",
			"failed to init scene"));
	}
	init_list_head(&self->entities);
	init_list_head(&self->blocks);
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self, args);
	self->screen_ref = args->screen;
	if (self->super.module.has_error == FALSE
		&& self->super.entities.module.has_error == FALSE)
	{
		init_radio_group(&self->hud.tools,
			(t_checkbox_entity**const)&self->hud.tools_group,
			sizeof(self->hud.tools_group) / sizeof(t_checkbox_entity*), 0);
		init_radio_group(&self->hud.create,
			(t_checkbox_entity**const)&self->hud.create_group,
			sizeof(self->hud.create_group) / sizeof(t_checkbox_entity*), 0);
		init_radio_group(&self->hud.blocks,
			(t_checkbox_entity**const)&self->hud.blocks_group,
			sizeof(self->hud.blocks_group) / sizeof(t_checkbox_entity*), 0);
		block_checkbox_set_relative(self->hud.blocks_group.blue_ice,
			ft_checkbox_position(self->hud.create_group.show_blocks_ref, BELOW,
			50.0f));
		block_checkbox_set_relative(self->hud.blocks_group.white_wool,
			ft_checkbox_position(&self->hud.blocks_group.blue_ice->super.super,
			RIGHT_TO, 50.0f));
		block_checkbox_set_relative(self->hud.blocks_group.acacia_log,
			ft_checkbox_position(&self->hud.blocks_group.white_wool->super.super,
			RIGHT_TO, 50.0f));
	}
	else
	{
		destroy_new_editor_scene(self);
		return (throw_result_str("init_new_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}