/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:15:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

void	editor_scene_render(t_editor_scene *const self, t_frame *const fb)
{
	(void)self;
	frame_fill(fb, ft_rgba(64, 0, 0, 255));
	editor_grid_component_entity_render(
		(t_editor_component_entity*)self->grid_ref,
		self->camera_ref,
		fb);
	editor_vertex_component_entity_render(
		(t_editor_component_entity*)self->vertex_ref,
		self->camera_ref,
		fb);
	// checkbox_entity_render(self->checkbox_ref, fb);
	// button_entity_render(self->start_game_ref, fb);
}
