/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:09:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/delta.h"

#include <stdio.h>

void	editor_scene_update(t_editor_scene *const self)
{
	static t_vec2f		old_pos = (t_vec2f){0.0f, 0.0f};
	t_vec2f				new_pos;
	t_vec2f				offset_pos;
	t_list_head			*pos;
	t_component_entity	*node;

	entity_list_update(&self->super.entities);
	new_pos = editor_camera_entity_screen_to_editor_camera_pos(
		self->camera_ref,
		&self->screen_ref->frame,
		window_get_mouse_pos(self->screen_ref));
	if (sfMouse_isButtonPressed(sfMouseLeft) && self->mode == CURSOR)
	{
		offset_pos = ft_vec2f(new_pos.x - old_pos.x, new_pos.y - old_pos.y);
		pos = &self->selected_components;
		while ((pos = pos->next) != &self->selected_components)
		{
			node = (t_component_entity*)((t_u8*)pos
				- __builtin_offsetof(t_component_entity, selection_node));
			node->super.transform.position.x += offset_pos.x;
			node->super.transform.position.y += offset_pos.y;
		}
	}
	old_pos = new_pos;
	printf("components: %lu\n", list_size(&self->components.list));
}