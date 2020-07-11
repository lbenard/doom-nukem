/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 21:11:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "engine/frame.h"
#include "engine/blend.h"
#include "ft/mem.h"

void	menu_scene_render(t_menu_scene *const self, t_frame *const fb)
{
	image_entity_render(self->background_ref, fb);
	button_entity_render(self->start_game_ref, fb);
	button_entity_render(self->editor_ref, fb);
	button_entity_render(self->close_game_ref, fb);
	image_entity_render(self->title_ref, fb);
	image_entity_render(self->vignette_ref, fb);
	frame_fill_blend(&self->credits.target, ft_rgba(0, 0, 0, 255),
		blend_colorize);
	frame_layer_transform_add(fb,
		&self->credits.target,
		ft_frame_transform(ft_vec2f(0.0f, 1.0f),
			ft_isize(10, fb->size.y - 5),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_fill_blend(&self->credits.target, ft_rgba(220, 220, 220, 255),
		blend_colorize);
	frame_layer_transform_add(fb,
		&self->credits.target,
		ft_frame_transform(ft_vec2f(0.0f, 1.0f),
			ft_isize(10 - 2, fb->size.y - 5 - 2),
			ft_vec2f(2.0f, 2.0f),
			255));
	// image_entity_render(self->credits_ref, fb);
}
