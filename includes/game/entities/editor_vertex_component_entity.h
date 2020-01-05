/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_vertex_component_entity.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:27:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 03:52:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_VERTEX_COMPONENT_ENTITY_H
# define EDITOR_VERTEX_COMPONENT_ENTITY_H

# include "game/entities/editor_component_entity.h"

typedef struct	s_editor_vertex_component_entity
{
	t_editor_component_entity	super;
	const t_frame				*vertex_ref;
	const t_frame				*vertex_selected_ref;
}				t_editor_vertex_component_entity;

typedef struct	s_editor_vertex_component_entity_args
{
	t_vec2f			position;
	const t_frame	*vertex_ref;
	const t_frame	*vertex_selected_ref;
}				t_editor_vertex_component_entity_args;

t_constructor	editor_vertex_component_entity(const t_vec2f position,
					const t_frame *const vertex_ref,
					const t_frame *const vertex_selected_ref);

t_result		init_editor_vertex_component_entity(
					t_editor_vertex_component_entity *const self,
					const t_editor_vertex_component_entity_args *const args);

void			editor_vertex_component_entity_update(
					t_editor_vertex_component_entity *const self);
void			editor_vertex_component_entity_render(
					t_editor_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const frame);

t_bool			editor_vertex_component_entity_is_selected(
					t_editor_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_editor_vertex_component_entity(
					t_editor_vertex_component_entity *const self);

#endif