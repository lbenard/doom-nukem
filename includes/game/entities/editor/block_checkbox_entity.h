/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_checkbox_entity.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:28:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:31:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_CHECKBOX_ENTITY_H
# define BLOCK_CHECKBOX_ENTITY_H

# include "game/entities/editor/preview_checkbox_entity.h"
# include "game/scenes/editor_block_descriptor.h"

typedef struct			s_block_checkbox_entity
{
	t_preview_checkbox_entity		super;
	const t_editor_block_descriptor	*block;
}						t_block_checkbox_entity;

typedef struct			s_block_checkbox_entity_args
{
	const char						*base_name;
	const t_editor_block_descriptor	*block;
	const t_window					*window;
}						t_block_checkbox_entity_args;

t_constructor			block_checkbox_entity(const char *const base_name,
							const t_editor_block_descriptor *const block,
							const t_window *const window);

t_result				init_block_checkbox_entity(
							t_block_checkbox_entity *const self,
							const t_block_checkbox_entity_args *const args);

void					block_checkbox_entity_update(
							t_block_checkbox_entity *const self);
void					block_checkbox_entity_render(
							t_block_checkbox_entity *const self,
							t_frame *const frame);

void					destroy_block_checkbox_entity(
							t_block_checkbox_entity *const self);

t_block_checkbox_entity	*create_block_checkbox(t_entity_list *const list,
							const char *const base_name,
							const t_editor_block_descriptor *const block,
							const t_window *const window);

void					block_checkbox_set_relative(
							t_block_checkbox_entity *const self,
							const t_checkbox_position position);
void					block_checkbox_set_pos(
							t_block_checkbox_entity *const self, 
							const t_vec3f pos);


#endif