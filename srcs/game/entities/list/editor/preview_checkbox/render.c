/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:04:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:57:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "game/entities/editor/preview_checkbox_entity.h"
#include "game/game.h"

void	preview_checkbox_entity_render(t_preview_checkbox_entity *const self,
			t_frame *const frame)
{
	t_vec2i	mouse;
	t_usize	cursor_size;
	t_vec2f	scale;

	SDL_GetMouseState(&mouse.x, &mouse.y);
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
