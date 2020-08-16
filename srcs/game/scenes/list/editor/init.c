/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 04:25:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"
#include "game/game.h"
#include "engine/map.h"
#include "maths/maths.h"

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

static void	add_block_buttons(t_editor_scene *const self,
				const t_editor_scene_args *const args,
				t_game *const game)
{
	t_block_descriptor		*descriptors;
	size_t					descriptors_size;
	t_block_checkbox_entity	**buttons;
	size_t					buttons_size;
	size_t					i;

	descriptors = (t_block_descriptor*)&game->blocks_list;
	descriptors_size = sizeof(game->blocks_list) / sizeof(*descriptors);
	buttons = (t_block_checkbox_entity**)&self->hud.blocks_group;
	buttons_size = sizeof(self->hud.blocks_group) / sizeof(*buttons);
	i = 0;
	while (i < ft_smin(descriptors_size, buttons_size))
	{
		buttons[i] = create_block_checkbox(
			&self->super.entities, "editor-button.bmp",
			&descriptors[i], args->screen);
		if (buttons[i])
		{
			if (i % 6 == 0)
			{
				if (i == 0)
					block_checkbox_set_relative(buttons[i],
						ft_checkbox_position((t_checkbox_entity*)
							self->hud.create_group.show_blocks_ref, BELOW,
						50.0f));
				else
					block_checkbox_set_relative(buttons[i],
						ft_checkbox_position((t_checkbox_entity*)buttons[i - 6],
						BELOW, 50.0f));
			}
			else
				block_checkbox_set_relative(buttons[i],
					ft_checkbox_position((t_checkbox_entity*)buttons[i - 1],
					RIGHT_TO, 50.0f));
		}
		i++;
	}
}

static void	add_entity_buttons(t_editor_scene *const self,
				const t_editor_scene_args *const args,
				t_game *const game)
{
	t_entity_descriptor			*descriptors;
	size_t						descriptors_size;
	t_entity_checkbox_entity	**buttons;
	size_t						buttons_size;
	size_t						i;

	descriptors = (t_entity_descriptor*)&game->entities_list;
	descriptors_size = sizeof(game->entities_list) / sizeof(*descriptors);
	buttons = (t_entity_checkbox_entity**)&self->hud.entities_group;
	buttons_size = sizeof(self->hud.entities_group) / sizeof(*buttons);
	i = 0;
	while (i < ft_smin(descriptors_size, buttons_size))
	{
		buttons[i] = create_entity_checkbox(
			&self->super.entities, "editor-button.bmp",
			&descriptors[i], args->screen);
		if (buttons[i])
		{
			if (i % 5 == 0)
			{
				if (i == 0)
					entity_checkbox_set_relative(buttons[i],
						ft_checkbox_position((t_checkbox_entity*)
							self->hud.create_group.show_entities_ref, BELOW,
						50.0f));
				else
					entity_checkbox_set_relative(buttons[i],
						ft_checkbox_position((t_checkbox_entity*)buttons[i - 5],
						BELOW, 50.0f));
			}
			else
				entity_checkbox_set_relative(buttons[i],
					ft_checkbox_position((t_checkbox_entity*)buttons[i - 1],
					RIGHT_TO, 50.0f));
		}
		i++;
	}
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
				"resources/textures/editor-player-spawn.bmp")));
	self->hud.tools_group.cursor_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor-cursor.bmp", ft_checkbox_position_pos(
		ft_vec3f(self->editor_view.size.x + 30.0f, 30.0f, 0.0f)), args->screen);
	self->hud.tools_group.create_ref = create_checkbox_relative(
		&self->super.entities, "editor-create.bmp",
		ft_checkbox_position(self->hud.tools_group.cursor_ref, RIGHT_TO, 50.0f),
		args->screen);
	self->hud.tools_group.save_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor-save.bmp",
		ft_checkbox_position_pos(ft_vec3f(args->screen->size.x - 30,
		args->screen->size.y - 30, 0.0f)), args->screen);
	self->hud.create_group.show_blocks_ref = create_checkbox_relative(
		&self->super.entities, "editor-block.bmp", ft_checkbox_position(
		self->hud.tools_group.create_ref, BELOW, 50.0f), args->screen);
	self->hud.create_group.show_entities_ref = create_checkbox_relative(
		&self->super.entities, "editor-entity.bmp", ft_checkbox_position(
		self->hud.create_group.show_blocks_ref, RIGHT_TO, 50.0f), args->screen);
	add_block_buttons(self, args, game);
	add_entity_buttons(self, args, game);
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
	}
	else
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}
