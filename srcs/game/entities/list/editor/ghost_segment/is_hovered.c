/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hovered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:31:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:09:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

t_bool	ghost_segment_component_entity_is_hovered(
			t_component_entity *const self,
			t_editor_camera_entity *const camera,
			const t_frame *const frame,
			const t_isize mouse_pos)
{
	t_ghost_segment_component_entity	*entity;
	t_vec2f								camera_pos;

	entity = (t_ghost_segment_component_entity*)self;
	camera_pos = editor_camera_entity_screen_to_editor_camera_pos(
		camera,
		frame,
		mouse_pos);
	return (shape_is_point_in_shape(
		&entity->shape,
		ft_isize(camera_pos.x, camera_pos.y)
	));
}