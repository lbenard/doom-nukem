/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/29 23:10:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/delta.h"


void	editor_scene_update(t_editor_scene *const self)
{
	t_vec2f	new_pos;

	entity_list_update(&self->super.entities);
	if (sfMouse_isButtonPressed(sfMouseLeft))
	{
		if (self->selected_component && self->selected_component->is_moved)
		{
			new_pos = editor_camera_entity_screen_to_camera_pos(
				self->camera_ref,
				&self->screen_ref->frame,
				window_get_mouse_pos(self->screen_ref));
			self->selected_component->super.transform.position.x = new_pos.x;
			self->selected_component->super.transform.position.y = new_pos.y;
		}
	}
}