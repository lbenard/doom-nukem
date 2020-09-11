/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cursor_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:25:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 09:04:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/error.h"

static void		remove_component(t_editor_scene *const self)
{
	entity_list_remove(&self->super.entities,
		(t_entity*)self->selected_component_ref);
	entity_list_remove(&self->components,
		(t_entity*)self->selected_component_ref);
	entity_list_remove(&self->blocks,
		(t_entity*)self->selected_component_ref);
	entity_list_remove(&self->entities,
		(t_entity*)self->selected_component_ref);
	self->selected_component_ref = NULL;
}

static void		unselect_component(t_editor_scene *const self)
{
	if (self->selected_component_ref)
	{
		self->selected_component_ref->is_selected = FALSE;
		self->selected_component_ref->is_moved = FALSE;
		self->selected_component_ref = NULL;
	}
}

static void		select_component(t_editor_scene *const self,
					const SDL_Event *const event)
{
	t_list_head			*pos;
	t_component_entity	*component;

	pos = &self->components.list;
	while ((pos = pos->prev) != &self->components.list)
	{
		component = (t_component_entity*)((t_entity_node*)pos)->entity;
		if (event->button.button == SDL_BUTTON_LEFT
			|| event->button.button == SDL_BUTTON_RIGHT)
		{
			if (component->vtable.is_hovered(component, self->camera_ref,
				&self->editor_view,
				ft_isize(event->button.x, event->button.y)))
			{
				unselect_component(self);
				self->selected_component_ref = component;
				component->is_selected = TRUE;
				component->is_moved = TRUE;
				list_move_tail(pos, &self->components.list);
				break ;
			}
		}
	}
	if (pos == &self->components.list)
		unselect_component(self);
}

static void		component_cursor(t_editor_scene *const self, SDL_Event *event)
{
	if (self->hud.tools_group.cursor_ref->is_checked)
	{
		if (event->type == SDL_MOUSEBUTTONDOWN
			&& event->button.x < (ssize_t)self->editor_view.size.x
			&& event->button.y < (ssize_t)self->editor_view.size.y)
			select_component(self, event);
		if (event->type == SDL_MOUSEBUTTONUP
			&& self->selected_component_ref)
			unselect_component(self);
		if (event->type == SDL_KEYDOWN
			&& event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			unselect_component(self);
		if (event->type == SDL_KEYDOWN
			&& event->key.keysym.scancode == SDL_SCANCODE_DELETE)
			remove_component(self);
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
