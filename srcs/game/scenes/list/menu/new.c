/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 00:27:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/entities/button_entity.h"
#include "engine/entity_node.h"
#include "engine/error.h"

static void		add_buttons(t_menu_scene *const scene,
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

static void		add_images(t_menu_scene *const scene)
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

t_menu_scene	*new_menu_scene(const t_menu_scene_args *const args)
{
	t_menu_scene	*ret;

	if (!(ret = (t_menu_scene*)malloc(sizeof(t_menu_scene))))
		return (NULL);
	if (!init_scene(&ret->super, "Main menu", (void(*)())menu_scene_update,
		(void(*)())menu_scene_render))
	{
		free(ret);
		return (NULL);
	}
	ret->window_size = args->window->size;
	add_buttons(ret, args);
	add_images(ret);
	if (ret->super.module.has_error || ret->super.entities.module.has_error)
	{
		free_menu_scene(ret);
		return (throw_error_str("new_menu_scene()",
			"failed to create new menu scene"));
	}
	return (ret);
}
