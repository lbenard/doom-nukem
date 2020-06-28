/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vertex_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:27:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:39:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/shape.h"
#include "engine/error.h"

t_vertex_node	*new_vertex_node(const t_isize pos)
{
	t_vertex_node	*ret;

	if (!(ret = (t_vertex_node*)malloc(sizeof(t_vertex_node))))
	{
		return (throw_error_str("new_vertex_node()",
			"failed to allocate vertex node"));
	}
	init_list_head(&ret->node);
	ret->pos = pos;
	return (ret);
}
