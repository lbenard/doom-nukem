/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cursor_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:25:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 03:46:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "engine/error.h"

static void		unselect_component(t_new_editor_scene *const self)
{
	if (self->selected_component_ref)
	{
		self->selected_component_ref->is_selected = FALSE;
		self->selected_component_ref->is_moved = FALSE;
		self->selected_component_ref = NULL;
	}
}

static void		select_component(t_new_editor_scene *const self,
					const sfEvent *const event)
{
	t_list_head			*pos;
	t_entity_node		*node;
	t_component_entity	*component;

	pos = &self->components.list;
	while ((pos = pos->prev) != &self->components.list)
	{
		node = (t_entity_node*)pos;
		component = (t_component_entity*)node->entity;
		if (event->mouseButton.button == sfMouseLeft
			|| event->mouseButton.button == sfMouseRight)
		{
			if (component->vtable.is_hovered(component,
				self->camera_ref,
				&self->editor_view,
				ft_isize(event->mouseButton.x, event->mouseButton.y)))
			{
				unselect_component(self);
				self->selected_component_ref = component;
				component->is_selected = TRUE;
				// if (self->selected_component_ref
				// 	&& !component->is_selected)
				// 	unselect_component(self);
				// if (!component->is_selected)
				// 	self->selected_component_ref = component;
				component->is_moved = TRUE;
				list_move_tail(pos, &self->components.list);
				break ;
			}
		}
	}
	if (pos == &self->components.list)
		unselect_component(self);
}

static void		component_cursor(t_new_editor_scene *const self, sfEvent *event)
{
	if (self->hud.tools_group.cursor_ref->is_checked)
	{
		if (event->type == sfEvtMouseButtonPressed)
			select_component(self, event);
		if (event->type == sfEvtMouseButtonReleased
			&& self->selected_component_ref)
			unselect_component(self);
		if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
			unselect_component(self);
	}
}

t_callback_node	*new_cursor_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(component_cursor, NULL)))
	{
		return (throw_error_str("new_component_cursor_event()",
			"failed to create new component cursor event"));
	}
	return (node);
}
