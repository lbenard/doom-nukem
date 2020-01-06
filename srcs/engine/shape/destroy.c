/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:16:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/06 00:19:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/shape.h"

static void	destroy_vertices(t_list_head *const vertices)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_vertex_node	*node;

	pos = vertices;
	next = pos->next;
	while ((pos = next) != vertices)
	{
		next = pos->next;
		node = (t_vertex_node*)pos;
		free(node);
	}
}

void	destroy_shape(t_shape *const self)
{
	destroy_vertices(&self->vertices);
	destroy_module(&self->module);
}