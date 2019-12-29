/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/24 17:00:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

void	editor_scene_render(t_editor_scene *const self, t_frame *const fb)
{
	t_list_head					*pos;
	t_entity_node				*node;
	t_editor_component_entity	*component;

	frame_fill(fb, ft_rgba(64, 0, 0, 255));
	pos = &self->components.list;
	while ((pos = pos->next) != &self->components.list)
	{
		node = (t_entity_node*)pos;
		component = (t_editor_component_entity*)node->entity;
		component->vtable.render(component, self->camera_ref, fb);
	}
	// editor_grid_component_entity_render(
	// 	(t_editor_component_entity*)self->grid_ref,
	// 	self->camera_ref,
	// 	fb);
	// editor_vertex_component_entity_render(
	// 	(t_editor_component_entity*)self->vertex_ref,
	// 	self->camera_ref,
	// 	fb);
	frame_layer_transform(fb, &self->title.target,
		ft_frame_transform_position(ft_isize(fb->size.x / 2, fb->size.y / 2)),
		blend_add);
}
