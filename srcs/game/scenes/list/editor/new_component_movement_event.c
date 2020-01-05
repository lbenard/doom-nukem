/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_component_movement_event.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:25:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/29 23:09:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/error.h"

static void		unselect_all_components(t_editor_scene *const self)
{
	t_list_head					*pos;
	t_entity_node				*node;
	t_editor_component_entity	*component;

	pos = &self->components.list;
	while ((pos = pos->next) != &self->components.list)
	{
		node = (t_entity_node*)pos;
		component = (t_editor_component_entity*)node->entity;
		component->is_selected = FALSE;
		component->is_moved = FALSE;
	}
}

static void		select_component(t_editor_scene *const self, sfEvent *event)
{
	t_list_head					*pos;
	t_entity_node				*node;
	t_editor_component_entity	*component;

	pos = &self->components.list;
	unselect_all_components(self);
	while ((pos = pos->prev) != &self->components.list)
	{
		node = (t_entity_node*)pos;
		component = (t_editor_component_entity*)node->entity;
		if (event->mouseButton.button == sfMouseLeft
			|| event->mouseButton.button == sfMouseRight)
		{
			if (component->vtable.is_selected
				&& component->vtable.is_selected(component,
				self->camera_ref,
				&self->screen_ref->frame,
				ft_isize(event->mouseButton.x, event->mouseButton.y)))
			{
				component->is_selected = TRUE;
				component->is_moved = TRUE;
				self->selected_component = component;
				list_move_tail(pos, &self->components.list);
				break ;
			}
			else
				self->selected_component = NULL;
		}
	}
}

static void		unselect_component(t_editor_scene *const self)
{
	if (self->selected_component)
		self->selected_component->is_moved = FALSE;
}

static void		component_movement(t_editor_scene *const self, sfEvent *event)
{
	if (event->type == sfEvtMouseButtonPressed)
		select_component(self, event);
	else if (event->type == sfEvtMouseButtonReleased)
		unselect_component(self);
}

t_callback_node	*new_component_movement_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(component_movement, NULL)))
	{
		return (throw_error_str("new_component_movement_event()",
			"failed to create new component movement event"));
	}
	return (node);
}
