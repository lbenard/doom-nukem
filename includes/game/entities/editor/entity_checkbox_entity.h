/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_checkbox_entity.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:28:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 20:57:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CHECKBOX_ENTITY_H
# define ENTITY_CHECKBOX_ENTITY_H

# include "game/entities/editor/preview_checkbox_entity.h"
# include "game/entity_descriptor.h"

typedef struct				s_entity_checkbox_entity
{
	t_checkbox_entity			super;
	const t_entity_descriptor	*entity;
}							t_entity_checkbox_entity;

typedef struct				s_entity_checkbox_entity_args
{
	const char					*base_name;
	const t_entity_descriptor	*entity;
	const t_window				*window;
}							t_entity_checkbox_entity_args;

t_constructor				entity_checkbox_entity(const char *const base_name,
								const t_entity_descriptor *const entity,
								const t_window *const window);

t_result					init_entity_checkbox_entity(
								t_entity_checkbox_entity *const self,
								t_entity_checkbox_entity_args *const args);

void						entity_checkbox_entity_update(
								t_entity_checkbox_entity *const self);
void						entity_checkbox_entity_render(
								t_entity_checkbox_entity *const self,
								t_frame *const frame);

void						destroy_entity_checkbox_entity(
								t_entity_checkbox_entity *const self);

t_entity_checkbox_entity	*create_entity_checkbox(t_entity_list *const list,
								const char *const base_name,
								const t_entity_descriptor *const entity,
								const t_window *const window);

void						entity_checkbox_set_relative(
								t_entity_checkbox_entity *const self,
								const t_checkbox_position position);
void						entity_checkbox_set_pos(
								t_entity_checkbox_entity *const self,
								const t_vec3f pos);

#endif
