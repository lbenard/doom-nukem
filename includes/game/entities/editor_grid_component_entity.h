/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_grid_component_entity.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:45:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 17:55:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_GRID_COMPONENT_ENTITY_H
# define EDITOR_GRID_COMPONENT_ENTITY_H

# include "game/entities/editor_component_entity.h"
# include "game/entities/editor_camera_entity.h"

typedef struct	s_editor_grid_component_entity
{
	t_editor_component_entity	super;
	float						unit_size;
}				t_editor_grid_component_entity;

typedef struct	s_editor_grid_component_entity_args
{
	t_usize	frame_size;
}				t_editor_grid_component_entity_args;

t_constructor	editor_grid_component_entity(const t_usize frame_size);

t_result		init_editor_grid_component_entity(
					t_editor_grid_component_entity *const self,
					const t_editor_grid_component_entity_args *const args);

void			editor_grid_component_entity_update(
					t_editor_grid_component_entity *const self);
void			editor_grid_component_entity_render(
					t_editor_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame	*const frame);

void			destroy_editor_grid_component_entity(
					t_editor_grid_component_entity *const self);

#endif