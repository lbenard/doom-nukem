/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:33:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/26 22:29:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_update(t_frame *const self)
{
	// sfFont		*font;
	// sfText		*text;

	// font = sfFont_createFromFile("haxorville.ttf");
	// text = sfText_create();
	// sfText_setFont(text, font);
	// sfText_setString(text, "test");
	// sfText_setColor(text, sfColor_fromRGB(255, 255, 255));
	sfTexture_updateFromPixels((sfTexture*)
		sfRenderTexture_getTexture(self->render_texture),
		(sfUint8*)self->frame.array, self->size.x, self->size.y, 0, 0);
	// sfRenderTexture_drawText(self->render_texture, text, NULL);
	// sfRenderTexture_display(self->render_texture);
	// sfTexture_updateFromTexture((sfTexture*)
		// sfRenderTexture_getTexture(self->render_texture), (sfTexture*)
		// sfRenderTexture_getTexture(self->render_texture), 0, 0);
	// sfRenderTexture_display(self->render_texture);
}
