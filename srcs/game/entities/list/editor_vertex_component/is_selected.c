/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_selected.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 03:53:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 03:57:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"

t_bool	editor_vertex_component_entity_is_selected(
			t_editor_component_entity *const self,
			t_editor_camera_entity *const camera,
			const t_frame *const frame,
			const t_isize mouse_pos)
{
	t_editor_vertex_component_entity	*cast;
	t_isize								entity_pos;

	cast = (t_editor_vertex_component_entity*)self;
	entity_pos = editor_component_entity_screen_pos(self, camera, frame);
	return (mouse_pos.x >= entity_pos.x - (ssize_t)cast->vertex_ref->size.x / 2
		&& mouse_pos.x < entity_pos.x + (ssize_t)cast->vertex_ref->size.x / 2
		&& mouse_pos.y >= entity_pos.y - (ssize_t)cast->vertex_ref->size.y / 2
		&& mouse_pos.y < entity_pos.y + (ssize_t)cast->vertex_ref->size.y / 2);
}