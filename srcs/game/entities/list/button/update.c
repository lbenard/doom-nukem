/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:31:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 19:37:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

void	button_entity_update(t_button_entity *const self)
{
	sfVector2i	pos;

	pos = sfMouse_getPositionRenderWindow(self->window->window);
	if (pos.x >= self->super.transform.position.x
		&& pos.x < self->super.transform.position.x
			+ self->normal_texture.size.x
		&& pos.y >= self->super.transform.position.y
		&& pos.y < self->super.transform.position.y
			+ self->normal_texture.size.y)
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			if (self->is_dynamic)
				self->current_texture = &self->click_texture;
		}
		else if (self->current_texture == &self->click_texture)
			self->is_clicked = TRUE;
		else if (self->is_dynamic)
			self->current_texture = &self->hover_texture;
	}
	else if (self->is_dynamic)
		self->current_texture = &self->normal_texture;
}
