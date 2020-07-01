/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block_create_event.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 02:15:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"

#include <stdio.h>

static t_vec3f	grid_pos(t_new_editor_scene *const self,
					const t_isize mouse_pos)
{
	t_vec2f	pos;

	pos = editor_camera_entity_screen_to_editor_camera_pos(self->camera_ref,
		&self->editor_view, mouse_pos);
	if (pos.x < 0.0f)
		pos.x = (int)(pos.x - 1.0f);
	else
		pos.x = (int)pos.x;
	if (pos.y < 0.0f)
		pos.y = (int)(pos.y - 1.0f);
	else
		pos.y = (int)pos.y;
	return (ft_vec3f(pos.x, pos.y, 0.0f));
}

static void		block_create(t_new_editor_scene *const self, sfEvent *event)
{
	t_isize					mouse_pos;
	t_block_checkbox_entity	*checkbox;
	t_component_entity		*block;

	if (event->type == sfEvtMouseButtonPressed)
	{
		mouse_pos = ft_isize(event->mouseButton.x, event->mouseButton.y);
		if (mouse_pos.x >= 0
			&& mouse_pos.x < (ssize_t)self->editor_view.size.x
			&& mouse_pos.y >= 0
			&& mouse_pos.y < (ssize_t)self->editor_view.size.y)
		{
			if (self->hud.create_group.show_blocks_ref->is_active
				&& self->hud.create_group.show_blocks_ref->is_checked)
			{
				checkbox = (t_block_checkbox_entity*)self->hud.blocks.list[self->hud.blocks.last];
				block = (t_component_entity*)entity_list_add_entity_ref(
					&self->components,
					entity_list_add_entity(&self->super.entities,
						block_component_entity(checkbox->block)));
				if (block)
					block->super.transform.position = grid_pos(self, mouse_pos);
			}
		}
	}
}

t_callback_node	*new_block_create_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(block_create, NULL)))
	{
		return (throw_error_str("new_block_create_event()",
			"failed to create new component create event"));
	}
	return (node);
}
