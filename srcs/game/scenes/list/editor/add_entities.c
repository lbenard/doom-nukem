/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:33:14 by mribouch          #+#    #+#             */
/*   Updated: 2020/09/07 14:36:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "maths/maths.h"

static void	checkbox_position(t_editor_scene *const self,
				t_entity_checkbox_entity **buttons, size_t i)
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
			&self->super.entities, "editor/editor-button.bmp",
			&descriptors[i], args->screen);
		if (buttons[i])
			checkbox_position(self, buttons, i);
		i++;
	}
}

static void	add_groups(t_editor_scene *const self,
					const t_editor_scene_args *const args)
{
	self->hud.tools_group.cursor_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor/editor-cursor.bmp",
		ft_checkbox_position_pos(ft_vec3f(
			self->editor_view.size.x + 30.0f, 30.0f, 0.0f)), args->screen);
	self->hud.tools_group.create_ref = create_checkbox_relative(
		&self->super.entities, "editor/editor-create.bmp",
		ft_checkbox_position(self->hud.tools_group.cursor_ref, RIGHT_TO, 50.0f),
		args->screen);
	self->hud.tools_group.save_ref = create_checkbox_relative_pos(
		&self->super.entities, "editor/editor-save.bmp",
		ft_checkbox_position_pos(ft_vec3f(args->screen->size.x - 30,
		args->screen->size.y - 30, 0.0f)), args->screen);
	self->hud.create_group.show_blocks_ref = create_checkbox_relative(
		&self->super.entities, "editor/editor-block.bmp", ft_checkbox_position(
		self->hud.tools_group.create_ref, BELOW, 50.0f), args->screen);
	self->hud.create_group.show_entities_ref = create_checkbox_relative(
		&self->super.entities, "editor/editor-entity.bmp", ft_checkbox_position(
		self->hud.create_group.show_blocks_ref, RIGHT_TO, 50.0f), args->screen);
}

void		add_entities(t_editor_scene *const self,
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
	add_groups(self, args);
	add_block_buttons(self, args, game);
	add_entity_buttons(self, args, game);
}
