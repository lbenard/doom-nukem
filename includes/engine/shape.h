/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:43:53 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/06 13:45:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "sizes/isize.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"
# include "containers/module.h"
# include "containers/list.h"
# include "engine/frame.h"
# include "colors/rgba.h"

typedef struct	s_vertex_node
{
	t_list_head	node;
	t_isize		pos;
}				t_vertex_node;

t_vertex_node	*new_vertex_node(const t_isize pos);
t_bool			vertices_side(t_vec2f p, t_vec2f a, t_vec2f b);

typedef struct	s_shape_box
{
	t_isize	pos;
	t_usize	size;
}				t_shape_box;

t_shape_box		ft_shape_box(const t_usize size);

typedef struct	s_shape
{
	t_module	module;
	t_list_head	vertices;
	t_shape_box	box;
}				t_shape;

t_constructor	shape(void);

t_result		init_shape(t_shape *const self);

t_result		shape_push_vertex(t_shape *const self,
					t_vertex_node *const node);
void			shape_update_box(t_shape *const self);
void			shape_sort(t_shape *const self);
t_vec2f			shape_get_center(const t_shape *const self);
t_bool			shape_is_point_in_shape(const t_shape *const self,
					const t_isize pos);
void			shape_render(const t_shape *const self,
					const t_isize pos,
					t_frame *const framebuffer,
					const t_rgba color);

void			destroy_shape(t_shape *const self);

#endif
