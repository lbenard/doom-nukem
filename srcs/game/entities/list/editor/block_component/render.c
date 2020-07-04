/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:35:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 04:06:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"

void	block_component_entity_render(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const fb)
{
	t_block_component_entity	*cast;
	t_vec2f						scale;

	cast = (t_block_component_entity*)self;
	scale.x = camera->grid_unit / (float)cast->block->texture.size.x
		* camera->super.transform.scale.x;
	scale.y = camera->grid_unit / (float)cast->block->texture.size.y
		* camera->super.transform.scale.y;
	frame_layer_transform(fb,
		&cast->block->texture,
		ft_frame_transform(ft_vec2f(0.0f, 0.0f),
			component_entity_screen_pos(self, camera, fb),
			scale,
		(self->is_moved) ? 127 : 255),
		blend_add);
	(void)self;
	(void)camera;
	(void)fb;
}