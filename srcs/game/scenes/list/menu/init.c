/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:40:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/entities/button_entity.h"
#include "engine/entity_node.h"
#include "engine/error.h"

static void	add_buttons(t_menu_scene *const scene,
				const t_menu_scene_args *const args)
{
	scene->start_game_ref = (t_button_entity*)entity_list_add_entity(
		&scene->super.entities,
		dynamic_button_entity("resources/buttons/start-game-upscale.png",
			"resources/buttons/start-game-hover-upscale.png",
			"resources/buttons/start-game-click-upscale.png",
			args->window));
	scene->close_game_ref = (t_button_entity*)entity_list_add_entity(
		&scene->super.entities,
		dynamic_button_entity("resources/buttons/close-game-upscale.png",
			"resources/buttons/close-game-hover-upscale.png",
			"resources/buttons/close-game-click-upscale.png",
			args->window));
}

static void	add_images(t_menu_scene *const scene)
{
	scene->vignette_ref = (t_image_entity*)entity_list_add_entity(
		&scene->super.entities,
		image_entity_from_file("resources/textures/vignette.png"));
	scene->title_ref = (t_image_entity*)entity_list_add_entity(
		&scene->super.entities,
		image_entity_from_file("resources/texts/wolf3d-upscale.png"));
	scene->credits_ref = (t_image_entity*)entity_list_add_entity(
		&scene->super.entities,
		image_entity_from_file("resources/texts/credits-upscale.png"));
}

t_result	init_menu_scene(t_menu_scene *const self,
				const t_menu_scene_args *const args)
{
	if (!init_scene(&self->super, "Main menu", (void(*)())menu_scene_update,
		(void(*)())menu_scene_render))
	{
		return (throw_result_str("init_menu_scene()",
			"failed to init menu scene"));
	}
	self->window_size = args->window->size;
	add_buttons(self, args);
	add_images(self);
	if (self->super.module.has_error || self->super.entities.module.has_error)
	{
		destroy_menu_scene(self);
		return (throw_result_str("init_menu_scene()",
			"failed to create new menu scene"));
	}
	return (OK);
}
