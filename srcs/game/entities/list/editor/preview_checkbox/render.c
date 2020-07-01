/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:04:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:24:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"
#include "engine/game.h"

void	preview_checkbox_entity_render(t_preview_checkbox_entity *const self,
			t_frame *const frame)
{
	sfVector2i	mouse;
	t_usize		cursor_size;

	mouse = sfMouse_getPositionRenderWindow(self->super.window->window);
	cursor_size = game_singleton()->window.cursor.cursor.size;
	checkbox_entity_render(&self->super, frame);
	if (self->super.is_hovered)
	{
		frame_layer_transform(frame,
			self->preview,
			ft_frame_transform(ft_vec2f(0.0f, 0.0f),
				ft_isize(mouse.x + cursor_size.x, mouse.y + cursor_size.y),
				ft_vec2f(3.0f, 3.0f),
				255),
			blend_add);
	}
}