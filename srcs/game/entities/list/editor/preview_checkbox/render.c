/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:04:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 18:01:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"
#include "game/game.h"

void	preview_checkbox_entity_render(t_preview_checkbox_entity *const self,
			t_frame *const frame)
{
	sfVector2i	mouse;
	t_usize		cursor_size;
	t_vec2f		scale;

	mouse = sfMouse_getPositionRenderWindow(self->super.window->window);
	cursor_size = game_singleton()->window.cursor.cursor.size;
	checkbox_entity_render(&self->super, frame);
	scale.x = 200.0f / self->preview->size.x;
	scale.y = 200.0f / self->preview->size.y;
	if (self->super.is_hovered)
	{
		frame_layer_transform_add(frame,
			self->preview,
			ft_frame_transform(ft_vec2f(1.0f, 0.0f),
				ft_isize(mouse.x, mouse.y + cursor_size.y),
				scale,
				255));
	}
}
