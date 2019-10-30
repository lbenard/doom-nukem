/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:01:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "engine/frame.h"
#include "engine/blend.h"
#include "ft/mem.h"

void	menu_scene_render(t_menu_scene *const self, t_frame *const fb)
{
	frame_fill(fb, ft_rgba(33, 55, 71, 255));
	image_entity_render(self->vignette_ref, fb);
	button_entity_render(self->close_game_ref, fb);
	image_entity_render(self->title_ref, fb);
	image_entity_render(self->credits_ref, fb);
	button_entity_render(self->start_game_ref, fb);
}
