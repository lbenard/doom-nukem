/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_vertex_component_entity.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:35:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 20:37:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"

t_constructor	editor_vertex_component_entity(const t_vec2f position,
					const t_frame *const vertex_ref,
					const t_frame *const vertex_selected_ref)
{
	static t_editor_vertex_component_entity_args	args;

	args.position = position;
	args.vertex_ref = vertex_ref;
	args.vertex_selected_ref = vertex_selected_ref;
	return (ft_constructor(
		init_editor_vertex_component_entity,
		destroy_editor_vertex_component_entity,
		sizeof(t_editor_vertex_component_entity),
		&args));
}
