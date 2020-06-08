/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_editor_camera_zoom_event.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:25:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:04:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/input.h"
#include "engine/game.h"


static t_vec2f		get_scroll_relative_to_camera(sfEvent *event)
{
	t_vec2f	mid;
	t_usize	window;
	t_vec2f	ret;
	
	window = game_singleton()->window.size;
	mid = ft_vec2f((float)window.x / 2.0f, (float)window.y / 2.0f);
	ret.x = ((float)event->mouseWheelScroll.x - mid.x);
	ret.y = ((float)event->mouseWheelScroll.y - mid.y);
	return (ret);
}

static t_vec2f		get_previous_position(t_vec2f scroll_relative,
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
					sfEvent *event)
{
	float	delta;

	delta = (event->mouseWheelScroll.delta > 0.0f) ? 1.1f : 1.0f / 1.1f;
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
					sfEvent *event)
{
	t_vec2f	scroll_relative;
	t_vec2f	scroll_previous;
	t_vec2f	scroll_next;
		
	if (event->type == sfEvtMouseWheelScrolled)
	{
		scroll_relative = get_scroll_relative_to_camera(event);
		scroll_previous = get_previous_position(scroll_relative,
			self->super.transform, self->grid_unit);
		update_camera_scale(self, event);
		scroll_next.x = scroll_previous.x * self->super.transform.scale.x;
		scroll_next.y = scroll_previous.y * self->super.transform.scale.x;
		update_camera_position(self, scroll_next, scroll_relative);
	}
}

t_callback_node	*new_editor_camera_zoom_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(editor_camera_zoom_event, NULL)))
	{
		return (throw_error_str("new_editor_camera_zoom_event()",
			"failed to create new editor camera zoom event"));
	}
	return (node);
}
