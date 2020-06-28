/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:31:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:38:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

t_vec2f	shape_get_center(const t_shape *const self)
{
	t_vec2f				ret;
	const t_list_head	*pos;
	t_vertex_node		*node;
	size_t				vertices_amount;

	ret = ft_vec2f(0.0f, 0.0f);
	pos = &self->vertices;
	while ((pos = pos->next) != &self->vertices)
	{
		node = (t_vertex_node*)pos;
		ret.x += node->pos.x;
		ret.y += node->pos.y;
	}
	vertices_amount = list_size(&self->vertices);
	if (vertices_amount)
	{
		ret.x /= vertices_amount;
		ret.y /= vertices_amount;
	}
	return (ret);
}
