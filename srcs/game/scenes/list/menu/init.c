/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/20 20:33:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"
#include "game/scenes/menu_scene.h"
#include "game/entities/button_entity.h"
#include "engine/entity_node.h"
#include "engine/error.h"

static void	add_buttons(t_menu_scene *const scene,
				const t_menu_scene_args *const args)
{
	scene->start_game_ref = (t_button_entity*)entity_list_add_entity(
		&scene->super.entities,
		dynamic_button_entity("resources/buttons/menu/start-game.bmp",
			"resources/buttons/menu/start-game-hover.bmp",
			"resources/buttons/menu/start-game-click.bmp",
			args->window));
	scene->editor_ref = (t_button_entity*)entity_list_add_entity(
		&scene->super.entities,
		dynamic_button_entity("resources/buttons/menu/editor.bmp",
			"resources/buttons/menu/editor-hover.bmp",
			"resources/buttons/menu/editor-click.bmp",
			args->window));
	scene->close_game_ref = (t_button_entity*)entity_list_add_entity(
		&scene->super.entities,
		dynamic_button_entity("resources/buttons/menu/close-game.bmp",
			"resources/buttons/menu/close-game-hover.bmp",
			"resources/buttons/menu/close-game-click.bmp",
			args->window));
}

static void	add_images(t_menu_scene *const self, const t_usize window_size)
{
	self->vignette_ref = (t_image_entity*)entity_list_add_entity(
		&self->super.entities,
		image_entity_from_file("resources/textures/vignette.bmp",
			ft_frame_transform_position(ft_isize(window_size.x / 2,
				window_size.y / 2))));
	self->background_ref = (t_image_entity*)entity_list_add_entity(
		&self->super.entities,
		image_entity_from_file("resources/textures/blood-background.bmp",
			ft_frame_transform_position(ft_isize(window_size.x / 2,
				window_size.y / 2))));
	self->title_ref = (t_image_entity*)entity_list_add_entity(
		&self->super.entities,
		image_entity_from_file("resources/textures/doum.bmp",
			ft_frame_transform_default()));
	module_add(&self->super.module, &self->credits,
		text("resources/fonts/haxorville.bmp", ft_usize(window_size.x, 9)));
	if (!self->super.module.has_error)
	{
		text_set_ref(&self->credits,
			static_string_as_ref(ft_static_string("Handcrafted by lbenard, "
				"lugibone, mribouch & ppetitea")));
		text_render(&self->credits, ft_text_settings(ft_isize(0, 0), 9));
	}
}

static void	git_id(t_menu_scene *const self)
{
	char	id[7];

	ft_strcpy(id, "#");
	ft_strncat(id, GIT_ID, 5);
	module_add(&self->super.module, &self->git_id,
		text("resources/fonts/haxorville.bmp", ft_usize(5 * 6, 9)));
	if (self->super.module.has_error == FALSE)
	{
		text_set_ref(&self->git_id,
			static_string_as_ref(ft_static_string(id)));
		text_render(&self->git_id, ft_text_settings(ft_isize(0, 0), 9));
	}
}

t_result	init_menu_scene(t_menu_scene *const self,
				const t_menu_scene_args *const args)
{
	if (!init_scene(&self->super, "Main menu", (void(*)())menu_scene_update,
		(void(*)())menu_scene_render))
	{
		return (throw_result_str("init_menu_scene()", "init menu scene fail"));
	}
	self->window_size = args->window->size;
	self->path = args->path;
	add_buttons(self, args);
	add_images(self, args->window->size);
	git_id(self);
	if (self->super.module.has_error || self->super.entities.module.has_error)
	{
		destroy_menu_scene(self);
		return (throw_result_str("init_menu_scene()",
			"failed to create new menu scene"));
	}
	self->vignette_ref->transform.scale.x = args->window->size.x
		/ (float)self->vignette_ref->image.size.x;
	self->vignette_ref->transform.scale.y = args->window->size.y
		/ (float)self->vignette_ref->image.size.y;
	self->background_ref->transform.scale.x = args->window->size.x
		/ (float)self->background_ref->image.size.x;
	self->background_ref->transform.scale.y = args->window->size.y
		/ (float)self->background_ref->image.size.y;
	return (OK);
}
