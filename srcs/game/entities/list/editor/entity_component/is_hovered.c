/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hovered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:37:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/13 13:26:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_component_entity.h"

t_bool	entity_component_entity_is_hovered(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			const t_frame *const frame,
			const t_isize mouse_pos)
{
	t_isize	entity_pos;
	t_isize	texture_size;

	entity_pos = component_entity_screen_pos(self, camera, frame);
	texture_size.x = camera->grid_unit * camera->super.transform.scale.x;
	texture_size.y = camera->grid_unit * camera->super.transform.scale.y;
	return (mouse_pos.x >= entity_pos.x - texture_size.x / 2
		&& mouse_pos.x < entity_pos.x + texture_size.x / 2
		&& mouse_pos.y >= entity_pos.y - texture_size.y / 2
		&& mouse_pos.y < entity_pos.y + texture_size.y / 2);
}
