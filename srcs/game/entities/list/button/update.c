/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:31:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:45:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "game/entities/button_entity.h"

void	button_entity_update(t_button_entity *const self)
{
	t_vec2i	pos;

	SDL_GetMouseState(&pos.x, &pos.y);
	if (pos.x >= self->super.transform.position.x
		&& pos.x < self->super.transform.position.x
			+ self->normal_texture.size.x
		&& pos.y >= self->super.transform.position.y
		&& pos.y < self->super.transform.position.y
			+ self->normal_texture.size.y)
	{
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_LMASK)
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
