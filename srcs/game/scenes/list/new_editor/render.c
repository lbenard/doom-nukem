/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 02:27:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"

void	new_editor_scene_render(t_new_editor_scene *const self, t_frame *const fb)
{
	(void)self;
	// t_list_head			*pos;
	// t_entity_node		*node;
	// t_component_entity	*component;

	frame_fill(fb, ft_rgba(64, 0, 0, 255));
	// pos = &self->components.list;
	// while ((pos = pos->next) != &self->components.list)
	// {
	// 	node = (t_entity_node*)pos;
	// 	component = (t_component_entity*)node->entity;
	// 	component->vtable.render(component, self->camera_ref, fb);
	// }
	// checkbox_entity_render(self->hud.cursor_ref, fb);
	// checkbox_entity_render(self->hud.create_ref, fb);
	// new_editor_grid_component_entity_render(
	// 	(t_new_editor_component_entity*)self->grid_ref,
	// 	self->camera_ref,
	// 	fb);
	// new_editor_vertex_component_entity_render(
	// 	(t_new_editor_component_entity*)self->vertex_ref,
	// 	self->camera_ref,
	// 	fb);
}
