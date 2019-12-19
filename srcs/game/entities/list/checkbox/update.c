/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:05:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/14 19:42:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	checkbox_entity_update(t_checkbox_entity *const self)
{
	static t_bool	was_mouse_pressed = FALSE;
	t_bool			is_mouse_pressed;
	sfVector2i		pos;

	pos = sfMouse_getPositionRenderWindow(self->window->window);
	is_mouse_pressed = sfMouse_isButtonPressed(sfMouseLeft);
	if (pos.x >= self->super.transform.position.x
		&& pos.x < self->super.transform.position.x
			+ self->normal_texture.size.x
		&& pos.y >= self->super.transform.position.y
		&& pos.y < self->super.transform.position.y
			+ self->normal_texture.size.y)
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