/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_entity.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:15:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 02:28:48 by lbenard          ###   ########.fr       */
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
typedef struct		s_checkbox_entity
{
	t_entity		super;
	t_bool			is_active;
	t_bool			is_checked;
	t_bool			is_hovered;
	t_bool			was_mouse_pressed;
	const t_window	*window;
	t_frame			normal_texture;
	t_frame			hover_texture;
	t_frame			checked_texture;
	t_frame			*current_texture;
}					t_checkbox_entity;

typedef struct		s_checkbox_entity_args
{
	const char		*normal_texture_path;
	const char		*hover_texture_path;
	const char		*checked_texture_path;
	const char		*base_name;
	const char		*icon_name;
	const t_window	*window;
}					t_checkbox_entity_args;

t_constructor		checkbox_entity(const char *const normal_path,
						const char *const hover_path,
						const char *const checked_path,
						const t_window *const window);
t_constructor		checkbox_entity_base(const char *const base_name,
						const t_window *const window);
t_constructor		checkbox_entity_base_icon(const char *const base_name,
						const char *const icon_name,
						const t_window *const window);

t_result			init_checkbox_entity(t_checkbox_entity *const self,
						const t_checkbox_entity_args *const args);
t_result			init_checkbox_entity_base(t_checkbox_entity *const self,
						const t_checkbox_entity_args *const args);
t_result			init_checkbox_entity_base_icon(t_checkbox_entity *const self,
						const t_checkbox_entity_args *const args);

void				checkbox_entity_update(t_checkbox_entity *const self);
void				checkbox_entity_render(t_checkbox_entity *const self,
						t_frame *const frame);

void				destroy_checkbox_entity(t_checkbox_entity *const self);

t_checkbox_entity	*create_checkbox(t_entity_list *const list,
						const char *const name,
						const t_window *const window);

typedef enum		s_checkbox_side
{
	ON_TOP,
	RIGHT_TO,
	BELOW,
	LEFT_TO
}					t_checkbox_side;

typedef struct		s_checkbox_position
{
	const t_checkbox_entity	*relative;
	t_vec3f					relative_pos;
	t_checkbox_side			side;
	float					gap;
}					t_checkbox_position;

t_checkbox_position	ft_checkbox_position(
						const t_checkbox_entity *const relative,
						const t_checkbox_side side,
						const float gap);
t_checkbox_position	ft_checkbox_position_pos(const t_vec3f relative_pos);

t_checkbox_entity	*create_checkbox(t_entity_list *const list,
						const char *const name,
						const t_window *const window);

t_checkbox_entity	*create_checkbox_relative(t_entity_list *const list,
						const char *const name,
						const t_checkbox_position position,
						const t_window *const window);

t_checkbox_entity	*create_checkbox_relative_pos(t_entity_list *const list,
						const char *const name,
						const t_checkbox_position position,
						const t_window *const window);

void				checkbox_set_relative(t_checkbox_entity *const self,
						const t_checkbox_position position);
void				checkbox_set_pos(t_checkbox_entity *const self, 
						const t_vec3f pos);

/*
** Utils
*/

typedef struct		s_radio_group
{
	t_checkbox_entity	**list;
	size_t				size;
	size_t				last;
}					t_radio_group;

t_result			init_radio_group(t_radio_group *const self,
						t_checkbox_entity **const list,
						const size_t size,
						const size_t default_checkbox);

void				update_radio_group(t_radio_group *const self);
void				radio_group_set_active(t_radio_group *const self,
						const t_bool state);

#endif
