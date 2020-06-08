/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_component_cursor_event.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:25:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/14 05:06:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/error.h"

static void		unselect_all_components(t_editor_scene *const self)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_component_entity	*node;

	pos = &self->selected_components;
	next = pos->next;
	while ((pos = next) != &self->selected_components)
	{
		next = pos->next;
		node = (t_component_entity*)((t_u8*)pos
			- __builtin_offsetof(t_component_entity, selection_node));
		list_del_entry(&node->selection_node);
		init_list_head(&node->selection_node);
		node->is_moved = FALSE;
	}
}

static void		select_component(t_editor_scene *const self,
					const sfEvent *const event,
					const t_bool multiple_selection)
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
				&self->screen_ref->frame,
				ft_isize(event->mouseButton.x, event->mouseButton.y)))
			{
				if (!list_is_empty(&self->selected_components)
					&& list_is_empty(&component->selection_node)
					&& !multiple_selection)
					unselect_all_components(self);
				if (list_is_empty(&component->selection_node))
					list_add_entry(&component->selection_node,
						&self->selected_components);
				else if (multiple_selection)
				{
					list_del_entry(&component->selection_node);
					init_list_head(&component->selection_node);
				}
				component->is_moved = TRUE;
				list_move_tail(pos, &self->components.list);
				break ;
			}
		}
	}
	if (pos == &self->components.list && !multiple_selection)
		unselect_all_components(self);
}

static void		component_cursor(t_editor_scene *const self, sfEvent *event)
{
	static t_bool	multiple_selection = FALSE;
	if (self->mode == CURSOR)
	{
		if (event->type == sfEvtKeyPressed && event->key.code == sfKeyLControl)
			multiple_selection = TRUE;
		if (event->type == sfEvtKeyReleased && event->key.code == sfKeyLControl)
			multiple_selection = FALSE;
		if (event->type == sfEvtMouseButtonPressed)
			select_component(self, event, multiple_selection);
		if (event->type == sfEvtKeyPressed && event->key.code == sfKeyBackspace)
			unselect_all_components(self);
	}
}

t_callback_node	*new_component_cursor_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(component_cursor, NULL)))
	{
		return (throw_error_str("new_component_cursor_event()",
			"failed to create new component cursor event"));
	}
	return (node);
}
