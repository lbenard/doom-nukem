/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:13:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 10:56:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/blend.h"
#include "maths/vec2i.h"

void	window_update(t_window *const self)
{
	t_isize	mouse_pos;
	t_vec2i	pos;

	if (self->cursor.is_visible)
	{
		SDL_GetMouseState(&pos.x, &pos.y);
		mouse_pos.x = pos.x;
		mouse_pos.y = pos.y;
		frame_layer_add(&self->frame, &self->cursor.cursor, mouse_pos);
	}
	SDL_LockSurface(self->surface);
	SDL_memcpy(self->surface->pixels,
		self->frame.pixels,
		self->surface->h * self->surface->pitch);
	SDL_UnlockSurface(self->surface);
	SDL_UpdateWindowSurface(self->window);
	if (self->is_cleared)
		frame_clear(&self->frame);
}
