/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_entity_create_event.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 09:07:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/entity_component_entity.h"
#include "engine/error.h"
#include "maths/maths.h"

static void		entity_create(t_editor_scene *const self, SDL_Event *event)
{
	t_isize						mouse_pos;
	t_entity_checkbox_entity	*checkbox;
	t_vec2f						pos;

	if (event->type == SDL_MOUSEBUTTONDOWN
		&& event->button.x < (ssize_t)self->editor_view.size.x
		&& event->button.y < (ssize_t)self->editor_view.size.y)
	{
		mouse_pos = ft_isize(event->button.x, event->button.y);
		if (mouse_pos.x >= 0
			&& mouse_pos.x < (ssize_t)self->editor_view.size.x &&
			mouse_pos.y >= 0 && mouse_pos.y < (ssize_t)self->editor_view.size.y)
		{
			pos = editor_camera_entity_screen_to_editor_camera_pos(
				self->camera_ref,
				&self->editor_view, mouse_pos);
			if (self->hud.create_group.show_entities_ref->is_active
				&& self->hud.create_group.show_entities_ref->is_checked)
			{
				checkbox = (t_entity_checkbox_entity*)
					self->hud.entities.list[self->hud.entities.last];
				editor_scene_add_entity(self, checkbox->entity, pos);
			}
		}
	}
}

t_callback_node	*new_entity_create_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(entity_create, NULL)))
	{
		return (throw_error_str("new_entity_create_event()",
			"failed to create new component create event"));
	}
	return (node);
}
