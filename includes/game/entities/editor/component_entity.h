/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_entity.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:28:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 17:48:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_ENTITY_H
# define COMPONENT_ENTITY_H

# include "engine/entity.h"
# include "engine/frame.h"
# include "colors/rgb.h"
# include "sizes/usize.h"
# include "game/entities/editor/editor_camera_entity.h"

/*
** Abstract editor component entity, must be inherited in order to be used.
*/
typedef struct	s_component_entity
{
	t_entity			super;
	t_bool				selectable;
	t_bool				is_selected;
	t_bool				movable;
	t_bool				is_moved;
	t_rgb				color;
	t_rgb				selected_color;
	t_rgb				dragged_color;
	t_rgb				error_color;
	struct		s_component_entity_vtable
	{
		void	(*render)(struct s_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const frame);
		t_bool	(*is_hovered)(struct s_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);
	}					vtable;
}				t_component_entity;

typedef struct	s_component_entity_args
{
	struct s_component_entity_vtable	vtable;
}				t_component_entity_args;

t_constructor	component_entity(const struct s_component_entity_vtable vtable);

t_result		init_component_entity(t_component_entity *const self,
					t_component_entity_args *const args);

void			component_entity_update(t_component_entity *const self);
t_vec2f			component_entity_editor_camera_pos(
					const t_component_entity *const self,
					const t_editor_camera_entity *const camera);
t_isize			component_entity_screen_pos(
					const t_component_entity *const self,
					const t_editor_camera_entity *const camera,
					const t_frame *const screen);
t_bool			component_entity_is_selected(
					const t_component_entity *const self);

void			destroy_component_entity(t_component_entity *const self);

#endif
