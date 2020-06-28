/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_component_entity.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:45:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 20:51:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_COMPONENT_ENTITY_H
# define GRID_COMPONENT_ENTITY_H

# include "engine/entity.h"
# include "game/entities/editor/editor_camera_entity.h"

typedef struct	s_grid_component_entity
{
	t_entity	super;
	float		unit_size;
}				t_grid_component_entity;

typedef struct	s_grid_component_entity_args
{
	t_usize	frame_size;
}				t_grid_component_entity_args;

t_constructor	grid_component_entity(const t_usize frame_size);

t_result		init_grid_component_entity(t_grid_component_entity *const self,
					const t_grid_component_entity_args *const args);

void			grid_component_entity_update(
					t_grid_component_entity *const self);
void			grid_component_entity_render(
					t_grid_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame	*const frame);

t_bool			grid_component_entity_is_hovered(
					t_grid_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_grid_component_entity(
					t_grid_component_entity *const self);

#endif