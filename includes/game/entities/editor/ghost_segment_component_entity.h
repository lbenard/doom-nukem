/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_segment_component_entity.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:35:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:05:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GHOST_SEGMENT_COMPONENT_ENTITY_H
# define GHOST_SEGMENT_COMPONENT_ENTITY_H

# include "game/entities/editor/component_entity.h"
# include "game/entities/editor/vertex_component_entity.h"
# include "engine/shape.h"
# include "engine/window.h"

# define GHOST_SEGMENT_WIDTH 5

typedef struct	s_ghost_segment_component_entity
{
	t_component_entity				super;
	t_shape							shape;
	t_isize							a;
	t_isize							b;
	const t_vertex_component_entity	*vertex_ref;
	const t_editor_camera_entity	*camera_ref;
	const t_window					*screen_ref;
}				t_ghost_segment_component_entity;

typedef struct	s_ghost_segment_component_entity_args
{
	t_vec2f							start_pos;
	const t_vertex_component_entity	*start_vertex;
	const t_editor_camera_entity			*camera_ref;
	const t_window					*screen_ref;
}				t_ghost_segment_component_entity_args;

t_constructor	ghost_segment_component_entity(const t_vec2f start,
					const t_editor_camera_entity *const camera_ref,
					const t_window *const screen_ref);
t_constructor	ghost_segment_component_entity_vertex(
					const t_vertex_component_entity *const start_vertex,
					const t_editor_camera_entity *const camera_ref,
					const t_window *const screen_ref);

t_result		init_ghost_segment_component_entity_pos(
					t_ghost_segment_component_entity *const self,
					const t_ghost_segment_component_entity_args *const args);
t_result		init_ghost_segment_component_entity_vertex(
					t_ghost_segment_component_entity *const self,
					const t_ghost_segment_component_entity_args *const args);

void			ghost_segment_component_entity_update(
					t_ghost_segment_component_entity *const self);
void			ghost_segment_component_entity_render(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const frame);

t_bool			ghost_segment_component_entity_is_hovered(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_ghost_segment_component_entity(
					t_ghost_segment_component_entity *const self);

#endif