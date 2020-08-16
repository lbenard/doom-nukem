/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_component_entity.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:12:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:25:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_COMPONENT_ENTITY_H
# define ENTITY_COMPONENT_ENTITY_H

# include "game/entities/editor/component_entity.h"
# include "game/scenes/editor_scene.h"

typedef struct	s_entity_component_entity
{
	t_component_entity			super;
	const t_entity_descriptor	*entity;
	const t_entity_list			*entity_list;
}				t_entity_component_entity;

typedef struct	s_entity_component_entity_args
{
	const t_entity_descriptor	*entity;
	const t_entity_list			*entity_list;
}				t_entity_component_entity_args;

t_constructor	entity_component_entity(const t_entity_descriptor *entity,
					const t_entity_list *const entity_list);

t_result		init_entity_component_entity(
					t_entity_component_entity *const self,
					t_entity_component_entity_args *const args);

void			entity_component_entity_update(
					t_entity_component_entity *const self);
void			entity_component_entity_render(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const fb);
t_bool			entity_component_entity_is_hovered(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_entity_component_entity(
					t_entity_component_entity *const self);

#endif
