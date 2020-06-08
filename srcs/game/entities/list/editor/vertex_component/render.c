/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:50:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:06:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/vertex_component_entity.h"

void	vertex_component_entity_render(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const frame)
{
	t_vertex_component_entity	*cast;

	cast = (t_vertex_component_entity*)self;
	if (!list_is_empty(&self->selection_node))
		frame_layer_transform(
			frame,
			cast->vertex_selected_ref,
			ft_frame_transform_position(component_entity_screen_pos(
				self,
				camera,
				frame)),
			blend_add);
	else
		frame_layer_transform(
			frame,
			cast->vertex_ref,
			ft_frame_transform_position(component_entity_screen_pos(
				self,
				camera,
				frame)),
			blend_add);
}