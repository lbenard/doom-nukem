/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:13:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/31 00:22:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/blend.h"

void	window_update(t_window *const self)
{
	t_isize	mouse_pos;

	frame_update(&self->frame);
	if (self->cursor.is_visible)
	{
		mouse_pos.x = sfMouse_getPositionRenderWindow(self->window).x;
		mouse_pos.y = sfMouse_getPositionRenderWindow(self->window).y;
		frame_layer(&self->frame, &self->cursor.cursor, mouse_pos, blend_add);
	}
	frame_update(&self->frame);
	sfRenderWindow_drawSprite(self->window, self->frame.sprite.sprite, NULL);
	sfRenderWindow_display(self->window);
	if (self->is_cleared)
		frame_clear(&self->frame);
}
