/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:18:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:40:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

static t_bool	is_polygon_side(t_shape *const self,
					const t_vertex_node *a,
					const t_vertex_node *b,
					const t_vec2f center)
{
	t_bool			side;
	t_list_head		*pos;
	t_vertex_node	*node;

	pos = &self->vertices;
	side = vertices_side(center,
		ft_vec2f(a->pos.x, a->pos.y),
		ft_vec2f(b->pos.x, b->pos.y));
	while ((pos = pos->next) != &self->vertices)
	{
		node = (t_vertex_node*)pos;
		if ((t_vertex_node*)pos != a && (t_vertex_node*)pos != b
			&& side != vertices_side(ft_vec2f(node->pos.x, node->pos.y),
				ft_vec2f(a->pos.x, a->pos.y),
				ft_vec2f(b->pos.x, b->pos.y)))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

void			shape_sort(t_shape *const self)
{
	t_vec2f			center;
	t_list_head		*pos;
	t_vertex_node	*node;
	t_list_head		*search;
	t_vertex_node	*search_node;

	center = shape_get_center(self);
	pos = &self->vertices;
	while ((pos = pos->next) != &self->vertices)
	{
		node = (t_vertex_node*)pos;
		search = pos;
		while ((search = search->next) != pos)
		{
			search_node = (t_vertex_node*)search;
			if (is_polygon_side(self, node, search_node, center))
			{
				list_del_entry(search);
				list_add(search, pos, pos->next);
				break ;
			}
		}
	}
}
