/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_component_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:35:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/08 15:27:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/vertex_component_entity.h"

t_constructor	vertex_component_entity(const t_vec2f position,
					const t_frame *const vertex_ref,
					const t_frame *const vertex_selected_ref)
{
	static t_vertex_component_entity_args	args;

	args.position = position;
	args.vertex_ref = vertex_ref;
	args.vertex_selected_ref = vertex_selected_ref;
	return (ft_constructor(
		init_vertex_component_entity,
		destroy_vertex_component_entity,
		sizeof(t_vertex_component_entity),
		&args));
}
