/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:02:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SCENE_H
# define EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/text.h"
# include "engine/shape.h"
# include "game/entities/editor/editor_camera_entity.h"
# include "game/entities/editor/grid_component_entity.h"
# include "game/entities/editor/vertex_component_entity.h"
# include "game/entities/checkbox_entity.h"

typedef enum	s_editor_mode
{
	CURSOR,
	CREATE,
	SPLIT,
	SECTORIZE
}				t_editor_mode;

typedef struct	s_editor_scene
{
	t_scene						super;
	t_editor_mode				mode;
	t_entity_list				components;
	t_frame						vertex_texture;
	t_frame						vertex_selected_texture;
	struct s_hud
	{
		t_checkbox_entity	*cursor_ref;
		t_checkbox_entity	*create_ref;
		t_checkbox_entity	*split_ref;
		t_checkbox_entity	*sectorize_ref;
	}							hud;
	t_editor_camera_entity		*camera_ref;
	t_list_head					selected_components;
	const t_window				*screen_ref;
}				t_editor_scene;

typedef struct	s_editor_scene_args
{
	const char		*path;
	const t_window	*screen;
}				t_editor_scene_args;

t_constructor	editor_scene(const t_window *const screen);
// t_constructor	editor_scene_from_file(const t_usize window_size,
// 					const char *const path);

t_result		init_editor_scene(t_editor_scene *const self,
					const t_editor_scene_args *const args);
// t_result		init_editor_scene_from_file(t_editor_scene *const self,
// 					const t_editor_scene_args *const args);

void			editor_scene_update(t_editor_scene *const self);
void			editor_scene_render(t_editor_scene *const self,
					t_frame *const fb);

void			destroy_editor_scene(t_editor_scene *const self);

t_callback_node	*new_component_cursor_event(void);
t_callback_node	*new_component_create_event(void);

#endif