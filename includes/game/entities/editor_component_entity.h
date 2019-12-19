/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_component_entity.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:28:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:36:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_COMPONENT_ENTITY_H
# define EDITOR_COMPONENT_ENTITY_H

# include "engine/entity.h"
# include "engine/frame.h"
# include "colors/rgb.h"
# include "sizes/usize.h"
# include "game/entities/editor_camera_entity.h"

typedef enum	s_editor_component_type
{
	VERTEX,
	SEGMENT,
	SECTOR,
	GRID
}				t_editor_component_type;

/*
** Abstract editor component entity, must be inherited in order to be used.
*/
typedef struct	s_editor_component_entity
{
	t_entity				super;
	t_editor_component_type	type;
	t_bool					is_movable;
	t_rgb					color;
	t_rgb					selected_color;
	t_rgb					dragged_color;
	t_rgb					error_color;
	struct s_editor_component_entity_vtable
	{
		void	(*render)(struct s_editor_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const frame);
		t_bool	(*is_selected)(struct s_editor_component_entity *const,
					const t_isize cursor_pos);
	}						vtable;
}				t_editor_component_entity;

typedef struct	s_editor_component_entity_args
{
	t_editor_component_type					type;
	struct s_editor_component_entity_vtable	vtable;
}				t_editor_component_entity_args;

t_result		init_editor_component_entity(
					t_editor_component_entity *const self,
					const t_editor_component_type type,
					const struct s_editor_component_entity_vtable vtable);

void			editor_component_entity_update(
					t_editor_component_entity *const self);
t_vec2f			editor_component_entity_camera_pos(
					t_editor_component_entity *const self,
					t_editor_camera_entity *const camera);

void			destroy_editor_component_entity(
					t_editor_component_entity *const self);

#endif