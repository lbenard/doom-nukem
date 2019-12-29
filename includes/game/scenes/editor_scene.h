/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/25 22:29:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SCENE_H
# define EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/text.h"
# include "game/entities/editor_camera_entity.h"
# include "game/entities/editor_grid_component_entity.h"
# include "game/entities/editor_vertex_component_entity.h"

typedef struct	s_editor_scene
{
	t_scene								super;
	t_entity_list						components;
	t_frame								vertex_texture;
	t_frame								vertex_selected_texture;
	t_text								title;
	t_editor_grid_component_entity		*grid_ref;
	t_editor_vertex_component_entity	*vertex_ref;
	t_editor_camera_entity				*camera_ref;
	const t_window						*screen_ref;
	t_editor_component_entity			*selected_component;
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

t_callback_node	*new_component_movement_event(void);

#endif