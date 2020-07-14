/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hovered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:37:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 00:44:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"

t_bool	block_component_entity_is_hovered(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			const t_frame *const frame,
			const t_isize mouse_pos)
{
	t_isize	entity_pos;

	entity_pos = component_entity_screen_pos(self, camera, frame);
	return (mouse_pos.x >= entity_pos.x
		&& mouse_pos.x < entity_pos.x + camera->grid_unit
			* camera->super.transform.scale.x
		&& mouse_pos.y >= entity_pos.y
		&& mouse_pos.y < entity_pos.y + camera->grid_unit
			* camera->super.transform.scale.y);
}
