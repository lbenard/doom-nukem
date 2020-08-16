/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 23:39:27 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"
#include "game/game.h"
#include "engine/map.h"

static void	add_modules(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	module_add(&self->super.module,
		&self->editor_view,
		frame(ft_usize(args->screen->size.x - 400, args->screen->size.y),
			ft_rgba(64, 0, 0, 255)));
	module_add(&self->super.module,
		&self->editor_background,
		frame_from_file("resources/textures/bob.bmp"));
	module_add(&self->super.module, &self->components, entity_list());
	module_add(&self->super.module, &self->blocks, entity_list());
	module_add(&self->super.module, &self->entities, entity_list());
}

t_result	init_editor_scene(t_editor_scene *const self,
				const t_editor_scene_args *const args)
{
	if (init_scene(&self->super, "Editor", editor_scene_update,
		editor_scene_render) == ERROR)
	{
		return (throw_result_str("init_editor_scene()",
			"failed to init scene"));
	}
	self->selected_component_ref = NULL;
	self->path = args->path;
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self, args, game_singleton());
	fill_from_map(self, args->path);
	init_event_handler_callback(self);
	self->screen_ref = args->screen;
	if (self->super.module.has_error == FALSE
		&& self->super.entities.module.has_error == FALSE)
		init_radio_groups(self);
	else
	{
		destroy_editor_scene(self);
		return (throw_result_str("init_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}
