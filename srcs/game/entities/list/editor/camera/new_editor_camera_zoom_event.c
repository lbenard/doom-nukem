/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_editor_camera_zoom_event.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:32:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:56:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/input.h"
#include "game/game.h"

static t_vec2f	get_previous_position(t_vec2f scroll_relative,
					t_transform camera, float unit)
{
	t_vec2f	ret;
	float	zoom;

	zoom = camera.scale.x;
	ret.x = (camera.position.x * unit * zoom + scroll_relative.x) / zoom;
	ret.y = (camera.position.y * unit * zoom + scroll_relative.y) / zoom;
	return (ret);
}

static void		update_camera_scale(t_editor_camera_entity *const self,
					SDL_Event *event)
{
	float	delta;

	delta = (event->wheel.y > 0.0f) ? 1.1f : 1.0f / 1.1f;
	self->super.transform.scale.x *= delta;
	self->super.transform.scale.y *= delta;
	self->super.transform.scale.z *= delta;
}

static void		update_camera_position(t_editor_camera_entity *const self,
					t_vec2f pos, t_vec2f offset)
{
	float	zoom;
	float	unit;

	unit = self->grid_unit;
	zoom = self->super.transform.scale.x;
	self->super.transform.position.x = (pos.x - offset.x) / (zoom * unit);
	self->super.transform.position.y = (pos.y - offset.y) / (zoom * unit);
}

static void		editor_camera_zoom_event(t_editor_camera_entity *const self,
					SDL_Event *event,
					const t_frame *const fb)
{
	t_vec2f	scroll_relative;
	t_vec2f	scroll_previous;
	t_vec2f	scroll_next;
	t_vec2f	mid;
	t_vec2i	mouse;

	if (event->type == SDL_MOUSEWHEEL)
	{
		mid = ft_vec2f((float)fb->size.x / 2.0f, (float)fb->size.y / 2.0f);
		SDL_GetMouseState(&mouse.x, &mouse.y);
		scroll_relative.x = ((float)mouse.x - mid.x);
		scroll_relative.y = ((float)mouse.y - mid.y);
		scroll_previous = get_previous_position(scroll_relative,
			self->super.transform, self->grid_unit);
		update_camera_scale(self, event);
		scroll_next.x = scroll_previous.x * self->super.transform.scale.x;
		scroll_next.y = scroll_previous.y * self->super.transform.scale.x;
		update_camera_position(self, scroll_next, scroll_relative);
	}
}

t_callback_node	*new_editor_camera_zoom_event(const t_frame *const fb)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(editor_camera_zoom_event, (void*)fb)))
	{
		return (throw_error_str("editor_camera_zoom_event()",
			"failed to create new editor camera zoom event"));
	}
	return (node);
}
