/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_editor_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 22:44:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_EDITOR_SCENE_H
# define NEW_EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/text.h"
# include "engine/shape.h"
# include "game/entities/editor/editor_camera_entity.h"
# include "game/entities/editor/grid_component_entity.h"
# include "game/entities/editor/vertex_component_entity.h"
# include "game/entities/checkbox_entity.h"
# include "game/entities/editor/preview_checkbox_entity.h"

# define BUTTONS "resources/buttons/"

/*
** Block and entity lists
*/

typedef struct	s_editor_block_node
{
	t_list_head	node;
	char		*name;
	t_frame		texture;
}				t_editor_block_node;

typedef struct	s_editor_entity_node
{
	t_list_head		node;
	char			*name;
	t_constructor	constructor;
	t_frame			icon;
}				t_editor_entity_node;

typedef struct	s_new_editor_scene
{
	t_scene						super;
	t_usize						map_size;
	t_list_head					blocks;
	t_list_head					entities;
	t_frame						editor_view;
	t_frame						editor_background;
	t_frame						dinosaur;
	t_grid_component_entity		*grid_ref;
	struct s_hud
	{
		t_radio_group	tools;
		struct s_tools_group
		{
			t_checkbox_entity	*cursor_ref;
			t_checkbox_entity	*create_ref;
		}						tools_group;
		t_radio_group	create;
		struct s_create_group
		{
			t_checkbox_entity	*show_blocks_ref;
			t_checkbox_entity	*show_entities_ref;
		}						create_group;
		t_radio_group	blocks;
		struct s_blocks_group
		{
			t_checkbox_entity	*concrete_ref;
			t_checkbox_entity	*brick_ref;
		}						blocks_group;
		t_radio_group	entities;
		struct s_entities_group
		{
			t_checkbox_entity	*player_ref;
			t_checkbox_entity	*enemy_ref;
			t_checkbox_entity	*gun_ref;
			t_checkbox_entity	*ammo_ref;
		}						entities_group;
	}							hud;
	struct s_blocks
	{
		t_editor_block_node	blue_ice;
		t_editor_block_node	white_wool;
		t_editor_block_node	acacia_log;
	}							blocks_list;
	t_editor_camera_entity		*camera_ref;
	const t_window				*screen_ref;
}				t_new_editor_scene;

typedef struct	s_new_editor_scene_args
{
	const char		*path;
	const t_window	*screen;
}				t_new_editor_scene_args;

t_constructor	new_editor_scene(const t_window *const screen);
// t_constructor	new_editor_scene_from_file(const t_usize window_size,
// 					const char *const path);

t_result		init_new_editor_scene(t_new_editor_scene *const self,
					const t_new_editor_scene_args *const args);
// t_result		init_new_editor_scene_from_file(t_new_editor_scene *const self,
// 					const t_new_editor_scene_args *const args);

void			new_editor_scene_update(t_new_editor_scene *const self);
void			new_editor_scene_render(t_new_editor_scene *const self,
					t_frame *const fb);

void			destroy_new_editor_scene(t_new_editor_scene *const self);

#endif