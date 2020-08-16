/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_component_entity.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:12:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:54:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_COMPONENT_ENTITY_H
# define BLOCK_COMPONENT_ENTITY_H

# include "game/entities/editor/component_entity.h"
# include "game/scenes/editor_scene.h"

typedef struct	s_block_component_entity
{
	t_component_entity			super;
	t_vec3f						pos_before_move;
	t_bool						was_not_moved;
	const t_block_descriptor	*block;
	const t_entity_list			*block_list;
}				t_block_component_entity;

typedef struct	s_block_component_entity_args
{
	const t_block_descriptor	*block;
	const t_entity_list			*block_list;
}				t_block_component_entity_args;

t_constructor	block_component_entity(const t_block_descriptor *block,
					const t_entity_list *const block_list);

t_result		init_block_component_entity(
					t_block_component_entity *const self,
					t_block_component_entity_args *const args);

void			block_component_entity_update(
					t_block_component_entity *const self);
void			block_component_entity_render(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const fb);
t_bool			block_component_entity_is_hovered(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_block_component_entity(
					t_block_component_entity *const self);

#endif
