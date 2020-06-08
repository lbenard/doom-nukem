/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:55:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/21 09:42:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

void	ghost_segment_component_entity_update(
			t_ghost_segment_component_entity *const self)
{
	t_vertex_node	*first;
	t_vertex_node	*second;
	t_vertex_node	*third;
	t_vertex_node	*fourth;
	t_vec2f			dir;

	first = (t_vertex_node*)self->shape.vertices.next;
	second = (t_vertex_node*)first->node.next;
	third = (t_vertex_node*)second->node.next;
	fourth = (t_vertex_node*)third->node.next;
	self->a = component_entity_screen_pos(
		&self->super,
		self->camera_ref,
		&self->screen_ref->frame
	);
	if (self->a.x == self->b.x && self->a.y == self->b.y)
	{
		first->pos = ft_isize(self->a.x, self->a.y);
		second->pos = ft_isize(self->a.x, self->a.y);
		third->pos = ft_isize(self->a.x, self->a.y);
		fourth->pos = ft_isize(self->a.x, self->a.y);
	}
	else
	{
		dir = vec2f_normalize(ft_vec2f(self->b.x - self->a.x, self->b.y - self->a.y));
		first->pos = ft_isize(self->a.x - dir.y * GHOST_SEGMENT_WIDTH,
			self->a.y + dir.x * GHOST_SEGMENT_WIDTH);
		second->pos = ft_isize(self->a.x + dir.y * GHOST_SEGMENT_WIDTH,
			self->a.y - dir.x * GHOST_SEGMENT_WIDTH);
		third->pos = ft_isize(self->b.x + dir.y * GHOST_SEGMENT_WIDTH,
			self->b.y - dir.x * GHOST_SEGMENT_WIDTH);
		fourth->pos = ft_isize(self->b.x - dir.y * GHOST_SEGMENT_WIDTH,
			self->b.y + dir.x * GHOST_SEGMENT_WIDTH);
	}
	shape_update_box(&self->shape);
}