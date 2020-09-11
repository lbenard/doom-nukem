/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:05:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:49:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "game/entities/checkbox_entity.h"

static void	checkbox_entity_update2(t_checkbox_entity *const self,
				t_bool is_mouse_pressed,
				t_vec2i pos,
				t_frame_coordinates frame_coordinates)
{
	if ((ssize_t)pos.x >= frame_coordinates.start.x
		&& (ssize_t)pos.x < frame_coordinates.end.x
		&& (ssize_t)pos.y >= frame_coordinates.start.y
		&& (ssize_t)pos.y < frame_coordinates.end.y)
	{
		self->is_hovered = TRUE;
		self->current_texture = &self->hover_texture;
		if (is_mouse_pressed && self->was_mouse_pressed == FALSE)
			self->is_checked = !self->is_checked;
	}
	else
	{
		self->is_hovered = FALSE;
		self->current_texture = &self->normal_texture;
	}
	if (self->is_checked)
		self->current_texture = &self->checked_texture;
	self->was_mouse_pressed = is_mouse_pressed;
}

void		checkbox_entity_update(t_checkbox_entity *const self)
{
	t_bool				is_mouse_pressed;
	t_vec2i				pos;
	t_frame_coordinates	frame_coordinates;

	if (!self->is_active)
		return ;
	SDL_GetMouseState(&pos.x, &pos.y);
	is_mouse_pressed = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_LMASK;
	frame_coordinates = coordinates(
		self->current_texture,
		ft_frame_transform(
			ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.transform.position.x,
				self->super.transform.position.y),
			ft_vec2f(self->super.transform.scale.x,
				self->super.transform.scale.y),
			COLOR_OPAQUE));
	checkbox_entity_update2(self, is_mouse_pressed, pos, frame_coordinates);
}
