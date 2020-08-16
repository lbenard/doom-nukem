/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 00:56:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SCENE_H
# define EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/text.h"
# include "engine/shape.h"
# include "game/entities/editor/component_entity.h"
# include "game/entities/editor/editor_camera_entity.h"
# include "game/entities/editor/grid_component_entity.h"
# include "game/entities/editor/preview_checkbox_entity.h"
# include "game/entities/editor/block_checkbox_entity.h"
# include "game/entities/editor/entity_checkbox_entity.h"
# include "game/entities/editor/player_component_entity.h"
# include "game/entities/checkbox_entity.h"
# include "game/block_descriptor.h"

# define BUTTONS "resources/buttons/"

/*
** Block and entity lists
*/

typedef struct	s_editor_entity_node
{
	t_list_head		node;
	char			*name;
	t_constructor	constructor;
	t_frame			icon;
}				t_editor_entity_node;

typedef struct	s_editor_scene
{
	t_scene						super;
	const char					*path;
	t_usize						map_size;
	t_entity_list				components;
	t_entity_list				blocks;
	t_entity_list				entities;
	t_component_entity			*selected_component_ref;
	t_player_component_entity	*player_spawn_ref;
	t_frame						editor_view;
	t_frame						editor_background;
	t_grid_component_entity		*grid_ref;
	struct						s_hud
	{
		t_radio_group	tools;
		struct	s_tools_group
		{
			t_checkbox_entity	*cursor_ref;
			t_checkbox_entity	*create_ref;
			t_checkbox_entity	*save_ref;
		}						tools_group;
		t_radio_group	create;
		struct	s_create_group
		{
			t_checkbox_entity	*show_blocks_ref;
			t_checkbox_entity	*show_entities_ref;
		}						create_group;
		t_radio_group	blocks;
		struct	s_blocks_group
		{
			t_block_checkbox_entity	*sandstone;
			t_block_checkbox_entity	*metallic_wall;
			t_block_checkbox_entity	*metallic_crate;
			t_block_checkbox_entity	*metallic_door;
			t_block_checkbox_entity	*metallic_light_tile;
			t_block_checkbox_entity	*metallic_dark_tile;
			t_block_checkbox_entity	*metallic_red_button;
			t_block_checkbox_entity	*metallic_green_button;
			t_block_checkbox_entity	*metallic_blue_button;
			t_block_checkbox_entity	*metallic_red_door;
			t_block_checkbox_entity	*metallic_green_door;
			t_block_checkbox_entity	*metallic_blue_door;
		}						blocks_group;
		t_radio_group	entities;
		struct	s_entities_group
		{
			t_entity_checkbox_entity	*onepunchman;
			t_entity_checkbox_entity	*weird_alien;
			t_entity_checkbox_entity	*ghast;
			t_entity_checkbox_entity	*nyarlathotep;
			t_entity_checkbox_entity	*pistol;
			t_entity_checkbox_entity	*shotgun;
			t_entity_checkbox_entity	*minigun;
		}						entities_group;
	}							hud;
	t_editor_camera_entity		*camera_ref;
	const t_window				*screen_ref;
}				t_editor_scene;

typedef struct	s_editor_scene_args
{
	const char		*path;
	const t_window	*screen;
}				t_editor_scene_args;

t_constructor	editor_scene(const t_window *const screen,
					const char *const path);
/*
** t_constructor	editor_scene_from_file(const t_usize window_size,
** 					const char *const path);
*/
t_result		init_editor_scene(t_editor_scene *const self,
					const t_editor_scene_args *const args);
t_result		fill_from_map(t_editor_scene *const self,
					const char *const path);
/*
** t_result		init_editor_scene_from_file(t_editor_scene *const self,
** 					const t_editor_scene_args *const args);
*/
void			editor_scene_update(t_editor_scene *const self);
void			editor_scene_render(t_editor_scene *const self,
					t_frame *const fb);

t_result		editor_scene_export_map(t_editor_scene *const self);
t_result		editor_scene_add_block(t_editor_scene *const self,
					const t_block_descriptor *const block,
					const t_vec2f pos);
t_result		editor_scene_add_entity(t_editor_scene *const self,
					const t_entity_descriptor *const entity,
					const t_vec2f pos);

void			destroy_editor_scene(t_editor_scene *const self);

t_callback_node	*new_cursor_event(void);
t_callback_node	*new_block_create_event(void);
t_callback_node	*new_entity_create_event(void);

#endif
