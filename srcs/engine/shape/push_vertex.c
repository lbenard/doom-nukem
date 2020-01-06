/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:18:12 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 23:19:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"
#include "engine/error.h"

t_result	shape_push_vertex(t_shape *const self, t_vertex_node *const node)
{
	if (!node)
	{
		self->module.has_error = TRUE;
		return (throw_result_str("shape_push_vertex()",
			"node is not valid"));
	}
	list_add_entry(&node->node, &self->vertices);
	return (OK);
}
