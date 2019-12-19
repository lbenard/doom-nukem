/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_entity.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:15:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/14 17:03:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_ENTITY_H
# define CHECKBOX_ENTITY_H

# include "engine/entity.h"
# include "engine/entity_node.h"
# include "engine/window.h"
# include "engine/scene.h"
# include "engine/frame.h"

/*
** Checkbox entity, represent a clickable box that can be checked or not.
** It has an idle, hover and checked texture. The checkbox does not throw any
** event, `is_checked` is used to know if the box is checked.
*/
typedef struct	s_checkbox_entity
{
	t_entity		super;
	t_bool			is_checked;
	const t_window	*window;
	t_frame			normal_texture;
	t_frame			hover_texture;
	t_frame			checked_texture;
	t_frame			*current_texture;
}				t_checkbox_entity;

typedef struct	s_checkbox_entity_args
{
	const char		*normal_texture_path;
	const char		*hover_texture_path;
	const char		*checked_texture_path;
	const t_window	*window;
}				t_checkbox_entity_args;

t_constructor	checkbox_entity(const char *const normal_path,
					const char *const hover_path,
					const char *const checked_path,
					const t_window *const window);

t_result		init_checkbox_entity(t_checkbox_entity *const self,
					const t_checkbox_entity_args *const args);

void			checkbox_entity_update(t_checkbox_entity *const self);
void			checkbox_entity_render(t_checkbox_entity *const self,
					t_frame *const frame);

void			destroy_checkbox_entity(t_checkbox_entity *const self);

#endif
