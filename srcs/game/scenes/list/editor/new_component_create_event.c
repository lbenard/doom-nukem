/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_component_create_event.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:08:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/ghost_segment_component_entity.h"
#include "engine/error.h"

t_vertex_component_entity	*selected_vertex(t_editor_scene *const self,
								const t_isize mouse_pos)
{
	t_list_head					*pos;
	t_entity_node				*node;
	t_component_entity			*component;
	t_vertex_component_entity	*vertex;

	pos = &self->components.list;
	while ((pos = pos->next) != &self->components.list)
	{
		node = (t_entity_node*)pos;
		component = (t_component_entity*)node->entity;
		if (component->type == VERTEX)
		{
			vertex = (t_vertex_component_entity*)component;
			if (vertex_component_entity_is_hovered(component,
				self->camera_ref,
				&self->screen_ref->frame,
				mouse_pos))
			{
				return (vertex);
			}
		}
	}
	return (NULL);
}

static void		component_create(t_editor_scene *const self, sfEvent *event)
{
	t_isize									mouse_pos;
	static t_ghost_segment_component_entity	*ghost_segment = NULL;
	const t_vertex_component_entity			*vertex;

	if (self->mode == CREATE)
	{
		mouse_pos = window_get_mouse_pos(self->screen_ref);
		if (event->type == sfEvtMouseButtonPressed)
		{
			if ((vertex = selected_vertex(self, mouse_pos)))
				ghost_segment = (t_ghost_segment_component_entity*)
					entity_list_add_entity_ref(
						&self->components,
						entity_list_add_entity(
							&self->super.entities,
							ghost_segment_component_entity_vertex(
								vertex,
								self->camera_ref,
								self->screen_ref
							)
						)
					);
			else
				ghost_segment = (t_ghost_segment_component_entity*)
					entity_list_add_entity_ref(
						&self->components,
						entity_list_add_entity(
							&self->super.entities,
							ghost_segment_component_entity(
								editor_camera_entity_screen_to_editor_camera_pos(
									self->camera_ref,
									&self->screen_ref->frame,
									mouse_pos
								),
								self->camera_ref,
								self->screen_ref
							)
						)
					);
		}
		if (ghost_segment && event->type == sfEvtMouseMoved)
			ghost_segment->b = mouse_pos;
		if (event->type == sfEvtMouseButtonReleased)
		{
			if (!ghost_segment->vertex_ref)
			{
				entity_list_add_entity_ref(
					&self->components,
					entity_list_add_entity(
						&self->super.entities,
						vertex_component_entity(
							editor_camera_entity_screen_to_editor_camera_pos(
								self->camera_ref,
								&self->screen_ref->frame,
								ghost_segment->a
							),
							&self->vertex_texture,
							&self->vertex_selected_texture
						)
					)
				);
			}
			entity_list_add_entity_ref(
				&self->components,
				entity_list_add_entity(
					&self->super.entities,
					vertex_component_entity(
						editor_camera_entity_screen_to_editor_camera_pos(
							self->camera_ref,
							&self->screen_ref->frame,
							mouse_pos
						),
						&self->vertex_texture,
						&self->vertex_selected_texture
					)
				)
			);
			entity_list_remove(&self->super.entities, (t_entity*)ghost_segment);
			entity_list_remove(&self->components, (t_entity*)ghost_segment);
			ghost_segment = NULL;
			vertex = NULL;
		}
	}
}

t_callback_node	*new_component_create_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(component_create, NULL)))
	{
		return (throw_error_str("new_component_create_event()",
			"failed to create new component create event"));
	}
	return (node);
}
