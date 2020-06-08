/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_segment_component_entity.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:32:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:05:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

t_constructor	ghost_segment_component_entity(const t_vec2f start,
					const t_editor_camera_entity *const camera_ref,
					const t_window *const screen_ref)
{
	static t_ghost_segment_component_entity_args	args;

	args.start_pos = start;
	args.camera_ref = camera_ref;
	args.screen_ref = screen_ref;
	return (ft_constructor(init_ghost_segment_component_entity_pos,
		destroy_ghost_segment_component_entity,
		sizeof(t_ghost_segment_component_entity),
		&args));
}