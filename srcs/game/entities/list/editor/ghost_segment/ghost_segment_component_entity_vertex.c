/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_segment_component_entity_vertex.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:29:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:05:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

t_constructor	ghost_segment_component_entity_vertex(
					const t_vertex_component_entity *const start_vertex,
					const t_editor_camera_entity *const camera_ref,
					const t_window *const screen_ref)
{
	static t_ghost_segment_component_entity_args	args;

	args.start_vertex = start_vertex;
	args.camera_ref = camera_ref;
	args.screen_ref = screen_ref;
	return (ft_constructor(init_ghost_segment_component_entity_vertex,
		destroy_ghost_segment_component_entity,
		sizeof(t_ghost_segment_component_entity),
		&args));
}