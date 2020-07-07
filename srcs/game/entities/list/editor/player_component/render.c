/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:40:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 01:06:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/player_component_entity.h"

void	player_component_entity_render(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const fb)
{
	t_player_component_entity	*cast;
	t_vec2f						scale;

	cast = (t_player_component_entity*)self;
	scale.x = camera->grid_unit / (float)cast->spawn_icon.size.x
		* camera->super.transform.scale.x;
	scale.y = camera->grid_unit / (float)cast->spawn_icon.size.y
		* camera->super.transform.scale.y;
	frame_layer_transform(fb,
		&cast->spawn_icon,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			component_entity_screen_pos(self, camera, fb),
			scale,
			255),
		blend_add);
}
