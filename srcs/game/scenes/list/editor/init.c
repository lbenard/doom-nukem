/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:52:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"
#include "game/game.h"
#include "engine/map.h"

static void	add_modules(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	module_add(&self->super.module,
		&self->editor_view,
		frame(ft_usize(args->screen->size.x - 400, args->screen->size.y),
			ft_rgba(64, 0, 0, 255)));
	module_add(&self->super.module,
		&self->editor_background,
		frame_from_file("resources/textures/bob.jpg"));
	module_add(&self->super.module, &self->components, entity_list());
	module_add(&self->super.module, &self->blocks, entity_list());
	module_add(&self->super.module, &self->entities, entity_list());
}

static void	add_entities(t_editor_scene *const self,
				const t_editor_scene_args *const args,
				t_game *const game)
{
	self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
		&self->super.entities,
		editor_camera_entity(self->editor_view.size.y * 0.1f,
			&self->editor_view, &self->super));
	self->grid_ref = (t_grid_component_entity*)entity_list_add_entity_ref(
		&self->components, entity_list_add_entity(&self->super.entities,
			grid_component_entity(self->editor_view.size,
				self->camera_ref->grid_unit)));
	self->player_spawn_ref = (t_player_component_entity*)
		entity_list_add_entity_ref(&self->components,
			entity_list_add_entity(&self->super.entities,
			player_component_entity(
				"resources/textures/editor-player-spawn.png")));
	// Tools
	self->hud.tools_group.cursor_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor-cursor.png", ft_checkbox_position_pos(
		ft_vec3f(self->editor_view.size.x + 30.0f, 30.0f, 0.0f)), args->screen);
	self->hud.tools_group.create_ref = create_checkbox_relative(
		&self->super.entities, "editor-create.png",
		ft_checkbox_position(self->hud.tools_group.cursor_ref, RIGHT_TO, 50.0f),
		args->screen);
	self->hud.tools_group.save_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor-save.png",
		ft_checkbox_position_pos(ft_vec3f(args->screen->size.x - 30,
		args->screen->size.y - 30, 0.0f)), args->screen);

	self->hud.create_group.show_blocks_ref = create_checkbox_relative(
		&self->super.entities, "editor-block.png", ft_checkbox_position(
		self->hud.tools_group.create_ref, BELOW, 50.0f), args->screen);
	self->hud.create_group.show_entities_ref = create_checkbox_relative(
		&self->super.entities, "editor-entity.png", ft_checkbox_position(
		self->hud.create_group.show_blocks_ref, RIGHT_TO, 50.0f), args->screen);

	// Blocks
	self->hud.blocks_group.blue_ice = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		&game->blocks_list.blue_ice, args->screen);
	self->hud.blocks_group.white_wool = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		&game->blocks_list.white_wool, args->screen);
	self->hud.blocks_group.acacia_log = create_block_checkbox(
		&self->super.entities, "editor-button.png",
		&game->blocks_list.acacia_log, args->screen);

	self->hud.entities_group.onepunchman = create_entity_checkbox(
		&self->super.entities, "editor-button.png",
		&game->entities_list.onepunchman, args->screen);
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
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self, args, game_singleton());
	fill_from_map(self, args->path);
	event_handler_add_callback(&self->super.input_manager, new_cursor_event());
	event_handler_add_callback(&self->super.input_manager,
		new_block_create_event());
	event_handler_add_callback(&self->super.input_manager,
		new_entity_create_event());
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
		init_radio_group(&self->hud.entities,
			(t_checkbox_entity**const)&self->hud.entities_group,
			sizeof(self->hud.entities_group) / sizeof(t_checkbox_entity*), 0);
		block_checkbox_set_relative(self->hud.blocks_group.blue_ice,
			ft_checkbox_position(self->hud.create_group.show_blocks_ref, BELOW,
			50.0f));
		block_checkbox_set_relative(self->hud.blocks_group.white_wool,
			ft_checkbox_position(&self->hud.blocks_group.blue_ice->super.super,
			RIGHT_TO, 50.0f));
		block_checkbox_set_relative(self->hud.blocks_group.acacia_log,
			ft_checkbox_position(&self->hud.blocks_group.white_wool->super.super,
			RIGHT_TO, 50.0f));

		entity_checkbox_set_relative(self->hud.entities_group.onepunchman,
			ft_checkbox_position(self->hud.create_group.show_entities_ref, BELOW,
			50.0f));
		// block_checkbox_set_relative(self->hud.blocks_group.white_wool,
		// 	ft_checkbox_position(&self->hud.blocks_group.blue_ice->super.super,
		// 	RIGHT_TO, 50.0f));
		// block_checkbox_set_relative(self->hud.blocks_group.acacia_log,
		// 	ft_checkbox_position(&self->hud.blocks_group.white_wool->super.super,
		// 	RIGHT_TO, 50.0f));
	}
	else
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}