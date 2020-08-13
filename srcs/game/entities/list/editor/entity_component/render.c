/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:35:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/13 13:23:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_component_entity.h"

void	entity_component_entity_render(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const fb)
{
	t_entity_component_entity	*cast;
	t_vec2f						scale;

	cast = (t_entity_component_entity*)self;
	scale.x = camera->grid_unit / (float)cast->entity->icon.size.x
		* camera->super.transform.scale.x;
	scale.y = camera->grid_unit / (float)cast->entity->icon.size.y
		* camera->super.transform.scale.y;
	frame_layer_transform_add(fb,
		&cast->entity->icon,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			component_entity_screen_pos(self, camera, fb),
			scale,
		(self->is_moved) ? 127 : 255));
}
