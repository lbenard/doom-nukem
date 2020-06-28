/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_checkbox_entity.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:28:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 19:46:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREVIEW_CHECKBOX_ENTITY_H
# define PREVIEW_CHECKBOX_ENTITY_H

# include "game/entities/checkbox_entity.h"

typedef struct	s_preview_checkbox_entity
{
	t_checkbox_entity	super;
	t_frame				preview;
}				t_preview_checkbox_entity;

typedef struct	s_preview_checkbox_entity_args
{
	const char		*normal_texture_path;
	const char		*hover_texture_path;
	const char		*checked_texture_path;
	const char		*preview_path;
	const t_window	*window;
}				t_preview_checkbox_entity_args;

t_constructor	preview_checkbox_entity(const char *const normal_path,
						const char *const hover_path,
						const char *const checked_path,
						const char *const preview_path,
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