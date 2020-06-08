/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:05:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/07 18:12:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	checkbox_entity_update(t_checkbox_entity *const self)
{
	static t_bool		was_mouse_pressed = FALSE;
	t_bool				is_mouse_pressed;
	sfVector2i			pos;
	t_frame_coordinates	frame_coordinates;

	pos = sfMouse_getPositionRenderWindow(self->window->window);
	is_mouse_pressed = sfMouse_isButtonPressed(sfMouseLeft);
	frame_coordinates = coordinates(
		self->current_texture,
		ft_frame_transform(
			ft_vec2f(0.5f, 0.5f),
			ft_isize(
				self->super.transform.position.x,
				self->super.transform.position.y
			),
			ft_vec2f(
				self->super.transform.scale.x,
				self->super.transform.scale.y
			),
			COLOR_OPAQUE
		)
	);
	if ((ssize_t)pos.x >= frame_coordinates.start.x
		&& (ssize_t)pos.x < frame_coordinates.end.x
		&& (ssize_t)pos.y >= frame_coordinates.start.y
		&& (ssize_t)pos.y < frame_coordinates.end.y)
	{
		self->current_texture = &self->hover_texture;
		if (is_mouse_pressed && was_mouse_pressed == FALSE)
			self->is_checked = !self->is_checked;
	}
	else
		self->current_texture = &self->normal_texture;
	if (self->is_checked)
		self->current_texture = &self->checked_texture;
	was_mouse_pressed = is_mouse_pressed;
}