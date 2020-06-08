/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_entity.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:21:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:08:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_CAMERA_ENTITY_H
# define EDITOR_CAMERA_ENTITY_H

# include "engine/entity.h"
# include "engine/event_handler.h"
# include "engine/input.h"
# include "engine/frame.h"

typedef struct	s_editor_camera_entity
{
	t_entity		super;
	t_event_handler	event_handler;
	float			grid_unit;
	t_input_id		up;
	t_input_id		right;
	t_input_id		down;
	t_input_id		left;
}				t_editor_camera_entity;

typedef struct	s_editor_camera_entity_args
{
	float	grid_unit;
}				t_editor_camera_entity_args;

t_constructor	editor_camera_entity(const float grid_unit);

t_result		init_editor_camera_entity(t_editor_camera_entity *const self,
					const t_editor_camera_entity_args *const args);

void			editor_camera_entity_update(t_editor_camera_entity *const self);

t_vec2f			editor_camera_entity_screen_to_editor_camera_pos(
					const t_editor_camera_entity *const self,
					const t_frame *const screen,
					const t_isize pos);
t_vec2f			editor_camera_entity_camera_pos(
					const t_editor_camera_entity *const self,
					t_vec2f pos);
t_isize			editor_camera_entity_camera_pos_to_screen(
					const t_editor_camera_entity *const self,
					const t_frame *const screen,
					const t_vec2f pos);

void			destroy_editor_camera_entity(
					t_editor_camera_entity *const self);

t_callback_node	*new_editor_camera_zoom_event(void);

#endif