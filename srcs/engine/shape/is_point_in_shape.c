/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_point_in_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:34:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/06 12:48:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

t_bool	shape_is_point_in_shape(const t_shape *const self, const t_isize pos)
{
	t_bool				odd_node;
	const t_list_head	*a;
	const t_list_head	*b;
	const t_vertex_node	*a_node;
	const t_vertex_node	*b_node;

	odd_node = FALSE;
	a = &self->vertices;
	b = self->vertices.prev->prev;
	while ((a = a->next) != &self->vertices
		&& (b = (b->next == &self->vertices) ? b->next->next : b->next))
	{
		a_node = (t_vertex_node*)a;
		b_node = (t_vertex_node*)b;
		if ((a_node->pos.y < pos.y && b_node->pos.y >= pos.y)
			|| (b_node->pos.y < pos.y && (a_node->pos.y >= pos.y)
			&& (a_node->pos.x <= pos.x || b_node->pos.x <= pos.x)))
		{
			if (a_node->pos.x + (pos.y - a_node->pos.y)
				/ (float)(b_node->pos.y - a_node->pos.y)
				* (b_node->pos.x - a_node->pos.x) <= pos.x)
				odd_node = !odd_node;
		}
	}
	return (odd_node);
}
