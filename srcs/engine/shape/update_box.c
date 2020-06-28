/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:19:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:38:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

void	shape_update_box(t_shape *const self)
{
	t_isize			min;
	t_isize			max;
	t_list_head		*pos;
	t_vertex_node	*node;

	pos = self->vertices.next;
	node = (t_vertex_node*)pos;
	min.x = node->pos.x;
	min.y = node->pos.y;
	max.x = node->pos.x;
	max.y = node->pos.y;
	while ((pos = pos->next) != &self->vertices)
	{
		node = (t_vertex_node*)pos;
		if (node->pos.x < min.x)
			min.x = node->pos.x;
		if (node->pos.y < min.y)
			min.y = node->pos.y;
		if (node->pos.x > max.x)
			max.x = node->pos.x;
		if (node->pos.y > max.y)
			max.y = node->pos.y;
	}
	self->box.pos = min;
	self->box.size = ft_usize((size_t)max.x - min.x, (size_t)max.y - min.y);
}
