/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera_zoom_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:25:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 20:09:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/input.h"
#include "engine/game.h"

#include <stdio.h>

static void		camera_zoom_event(t_editor_camera_entity *const self,
					sfEvent *event)
{
	float	delta;
	// t_usize	mid;
	// t_vec2f	previous_pos;
	// float	previous_scale;
	// t_vec2f	new_offset;
	
	if (event->type == sfEvtMouseWheelScrolled)
	{
		// mid = ft_usize(game_singleton()->window.size.x / 2,
		// 	game_singleton()->window.size.y / 2);

		// previous_pos.x = self->super.transform.position.x;
		// previous_pos.y = self->super.transform.position.y;
		// previous_scale = self->super.transform.scale.x;
		
		delta = (event->mouseWheelScroll.delta > 0.0f) ? 1.1f : 0.9;
		self->super.transform.scale.x *= delta;
		self->super.transform.scale.y *= delta;
		self->super.transform.scale.z *= delta;

		// new_offset.x = self->super.transform.position.x
		// 	+ (1.0f - (self->super.transform.scale.x / previous_scale))
		// 	* (event->mouseWheelScroll.x - previous_pos.x) / self->grid_unit;
		// new_offset.y = self->super.transform.position.y
		// 	+ (1.0f - (self->super.transform.scale.y / previous_scale))
		// 	* (event->mouseWheelScroll.y - previous_pos.y) / self->grid_unit;
		// self->super.transform.position.x += (float)((float)event->mouseWheelScroll.x - mid.x)
		// 	* self->super.transform.scale.x / self->grid_unit;
		//+= (offset.x
		//	* self->super.transform.scale.x - offset.x) / self->grid_unit;
		// self->super.transform.position.y += (offset.y
		// 	* self->super.transform.scale.y - offset.y) / self->grid_unit;
		// printf("pos x: %f\n", self->super.transform.position.x);
		// printf("pos y: %f\n", self->super.transform.position.y);
		// self->super.transform.position.x = new_offset.x;
		// self->super.transform.position.y = new_offset.y;
		// printf("pos x: %f\n", self->super.transform.position.x);
		// printf("pos y: %f\n", self->super.transform.position.y);
		// self->super.transform.position.y += (float)((float)event->mouseWheelScroll.y - mid.y)
		// 	* self->super.transform.scale.y / self->grid_unit;
		// printf("%f\n", self->super.transform.scale.x);
		// mid.x - event->mouseWheel.x;
	}
}

t_callback_node	*new_camera_zoom_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(camera_zoom_event, NULL)))
	{
		return (throw_error_str("new_camera_zoom_event()",
			"failed to create new camera zoom event"));
	}
	return (node);
}
