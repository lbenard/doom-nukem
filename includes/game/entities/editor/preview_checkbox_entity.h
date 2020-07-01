/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_checkbox_entity.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:28:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:24:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREVIEW_CHECKBOX_ENTITY_H
# define PREVIEW_CHECKBOX_ENTITY_H

# include "game/entities/checkbox_entity.h"

typedef struct	s_preview_checkbox_entity
{
	t_checkbox_entity	super;
	const t_frame		*preview;
}				t_preview_checkbox_entity;

typedef struct	s_preview_checkbox_entity_args
{
	const char		*base_name;
	const t_frame	*preview;
	const t_window	*window;
}				t_preview_checkbox_entity_args;

t_constructor	preview_checkbox_entity(const char *const base_name,
					const t_frame *const preview,
					const t_window *const window);

t_result		init_preview_checkbox_entity(
					t_preview_checkbox_entity *const self,
					const t_preview_checkbox_entity_args *const args);

void			preview_checkbox_entity_update(
					t_preview_checkbox_entity *const self);
void			preview_checkbox_entity_render(
					t_preview_checkbox_entity *const self,
					t_frame *const frame);

void			destroy_preview_checkbox_entity(
					t_preview_checkbox_entity *const self);

#endif