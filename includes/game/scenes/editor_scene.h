/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 10:55:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SCENE_H
# define EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/text.h"
# include "game/entities/editor/component_entity.h"
# include "game/entities/editor/editor_camera_entity.h"
# include "game/entities/editor/grid_component_entity.h"
# include "game/entities/editor/preview_checkbox_entity.h"
# include "game/entities/editor/block_checkbox_entity.h"
# include "game/entities/editor/entity_checkbox_entity.h"
# include "game/entities/editor/player_component_entity.h"
# include "game/entities/checkbox_entity.h"
# include "game/block_descriptor.h"
# include "game/game.h"

# define BUTTONS "resources/buttons/editor/"

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

/*
** Buttons groups
*/
typedef struct	s_tools_group
{
	t_checkbox_entity	*cursor_ref;
	t_checkbox_entity	*create_ref;
	t_checkbox_entity	*save_ref;
}				t_tools_group;

typedef struct	s_create_group
{
	t_checkbox_entity	*show_blocks_ref;
	t_checkbox_entity	*show_entities_ref;
}				t_create_group;

typedef struct	s_blocks_group
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
	t_block_checkbox_entity	*ending;
	t_block_checkbox_entity	*white_glass;
	t_block_checkbox_entity	*black_glass;
	t_block_checkbox_entity	*red_glass;
	t_block_checkbox_entity	*green_glass;
	t_block_checkbox_entity	*blue_glass;
	t_block_checkbox_entity	*andesite;
	t_block_checkbox_entity	*coarse_dirt;
	t_block_checkbox_entity	*wood_screen;
	t_block_checkbox_entity	*red_brick;
	t_block_checkbox_entity	*granite;
}				t_blocks_group;

typedef struct	s_entities_group
{
	t_entity_checkbox_entity	*widepunchman;
	t_entity_checkbox_entity	*weird_alien;
	t_entity_checkbox_entity	*ghast;
	t_entity_checkbox_entity	*nyarlathotep;
	t_entity_checkbox_entity	*lamp;
	t_entity_checkbox_entity	*pistol;
	t_entity_checkbox_entity	*shotgun;
	t_entity_checkbox_entity	*minigun;
	t_entity_checkbox_entity	*ammo;
	t_entity_checkbox_entity	*medikit;
}				t_entities_group;

typedef struct	s_editor_scene
{
	t_scene						super;
	const char					*path;
	t_usize						map_size;
	t_entity_list				components;
	t_entity_list				blocks;
	t_entity_list				entities;
	t_text						set_floor;
	t_frame						set_floor_key;
	t_input_id					set_floor_input;
	t_text						set_ceiling;
	t_frame						set_ceiling_key;
	t_input_id					set_ceiling_input;
	const t_block_descriptor	*floor;
	const t_block_descriptor	*ceiling;
	t_component_entity			*selected_component_ref;
	t_player_component_entity	*player_spawn_ref;
	t_frame						editor_view;
	t_frame						editor_background;
	t_grid_component_entity		*grid_ref;
	struct		s_hud
	{
		t_radio_group			tools;
		t_tools_group			tools_group;
		t_radio_group			create;
		t_create_group			create_group;
		t_radio_group			blocks;
		t_blocks_group			blocks_group;
		t_radio_group			entities;
		t_entities_group		entities_group;
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

t_result		init_editor_scene(t_editor_scene *const self,
					const t_editor_scene_args *const args);

void			init_event_handler_callback(t_editor_scene *const self);
void			init_radio_groups(t_editor_scene *const self);
void			add_entities(t_editor_scene *const self,
					const t_editor_scene_args *const args,
					t_game *const game);

t_result		fill_from_map(t_editor_scene *const self,
					const char *const path);

void			editor_scene_update(t_editor_scene *const self);
void			editor_scene_render(t_editor_scene *const self,
					t_frame *const fb);
void			add_block_buttons(t_editor_scene *const self,
					const t_editor_scene_args *const args,
					t_game *const game);

t_result		editor_scene_export_map(t_editor_scene *const self);
t_result		write_map(t_editor_scene *const self, const int fd,
					const t_isize origin, const t_usize size);
t_result		write_map_size(const int fd, const t_usize size);
t_result		write_player_spawn(const int fd,
					const t_player_component_entity *const player,
					const t_isize origin);
t_result		write_entities(t_editor_scene *const self,
					const int fd,
					const t_isize origin);
t_result		write_room(t_editor_scene *const self, const int fd);

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
