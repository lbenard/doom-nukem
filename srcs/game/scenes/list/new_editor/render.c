/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 16:34:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"

void	new_editor_scene_render(t_new_editor_scene *const self,
			t_frame *const fb)
{
	frame_fill(fb, ft_rgba(0, 0, 0, 255));
	if (sfKeyboard_isKeyPressed(sfKeyB))
		frame_layer_transform(fb,
			&self->editor_background,
			ft_frame_transform(ft_vec2f(1.0f, 0.5f),
				ft_isize(fb->size.x + 100, fb->size.y / 2),
				ft_vec2f(2.0f, 2.0f),
				64),
			blend_add);
	frame_fill(&self->editor_view, ft_rgba(34, 75, 120, 255));
	grid_component_entity_render(self->grid_ref,
		self->camera_ref,
		&self->editor_view);
	frame_layer_transform(
		&self->editor_view,
		&self->dinosaur,
		ft_frame_transform(
			ft_vec2f(0.5f, 0.5f),
			transform_screen_pos(
				ft_transform(
					ft_vec3f(0.0f, 0.0f, 0.0f),
					ft_vec3f(0.0f, 0.0f, 0.0f),
					ft_vec3f(1.0f, 1.0f, 1.0f)),
				self->camera_ref,
				&self->editor_view),
			vec3f_to_vec2f(self->camera_ref->super.transform.scale),
			255),
		blend_add);
	frame_layer(fb, &self->editor_view, ft_isize(0, 0), blend_add);
	checkbox_entity_render(self->hud.tools_group.create_ref, fb);
	checkbox_entity_render(self->hud.tools_group.cursor_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_blocks_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_entities_ref, fb);
}
