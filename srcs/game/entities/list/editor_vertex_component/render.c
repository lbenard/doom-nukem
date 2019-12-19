/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:50:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:37:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"

void	editor_vertex_component_entity_render(
			t_editor_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const frame)
{
	t_editor_vertex_component_entity	*cast;
	t_vec2f								pos;

	pos = editor_component_entity_camera_pos(self, camera);
	pos.x += frame->size.x / 2;
	pos.y += frame->size.y / 2;
	cast = (t_editor_vertex_component_entity*)self;
	frame_layer_transform(frame, cast->vertex_ref,
		ft_frame_transform_position(ft_isize(pos.x, pos.y)),
		blend_add);
}