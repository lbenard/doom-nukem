/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:17:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:12:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SCENE_H
# define EDITOR_SCENE_H

# include "engine/scene.h"
# include "engine/frame.h"
# include "game/entities/editor_camera_entity.h"
# include "game/entities/editor_grid_component_entity.h"
# include "game/entities/editor_vertex_component_entity.h"

typedef struct	s_editor_scene
{
	t_scene								super;
	t_editor_camera_entity				*camera_ref;
	t_editor_grid_component_entity		*grid_ref;
	t_editor_vertex_component_entity	*vertex_ref;
	t_frame								vertex_texture;
	t_frame								vertex_selected_texture;
	// t_list_head						components;
}				t_editor_scene;

typedef struct	s_editor_scene_args
{
	const char *path;
	t_usize		window_size;
}				t_editor_scene_args;

t_constructor	editor_scene(const t_usize window_size);
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

#endif