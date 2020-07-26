/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block_create_event.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/22 01:56:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"
#include "maths/maths.h"

static t_vec2f	grid_pos(t_editor_scene *const self,
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
	return (pos);
}

static t_bool	is_free(t_editor_scene *const self, const t_vec2f pos)
{
	t_list_head			*list_pos;
	t_component_entity	*block;

	list_pos = &self->blocks.list;
	while ((list_pos = list_pos->next) != &self->blocks.list)
	{
		block = (t_component_entity*)((t_entity_node*)list_pos)->entity;
		if (ft_fabs(block->super.transform.position.x - pos.x) < 0.001f
			&& ft_fabs(block->super.transform.position.y - pos.y) < 0.001f)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

static void		block_create(t_editor_scene *const self, sfEvent *event)
{
	t_isize					mouse_pos;
	t_block_checkbox_entity	*checkbox;
	t_vec2f					pos;

	if (event->type == sfEvtMouseButtonPressed
		&& event->mouseButton.x < (ssize_t)self->editor_view.size.x
		&& event->mouseButton.y < (ssize_t)self->editor_view.size.y)
	{
		mouse_pos = ft_isize(event->mouseButton.x, event->mouseButton.y);
		if (mouse_pos.x >= 0
			&& mouse_pos.x < (ssize_t)self->editor_view.size.x
			&& mouse_pos.y >= 0
			&& mouse_pos.y < (ssize_t)self->editor_view.size.y)
		{
			pos = grid_pos(self, mouse_pos);
			if (!is_free(self, pos))
				return ;
			if (self->hud.create_group.show_blocks_ref->is_active
				&& self->hud.create_group.show_blocks_ref->is_checked)
			{
				checkbox = (t_block_checkbox_entity*)
					self->hud.blocks.list[self->hud.blocks.last];
				editor_scene_add_block(self, checkbox->block, pos);
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
