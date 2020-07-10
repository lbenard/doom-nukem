/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/09 00:31:09 by lbenard          ###   ########.fr       */
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
	image_entity_render(self->credits_ref, fb);
	image_entity_render(self->vignette_ref, fb);
}
