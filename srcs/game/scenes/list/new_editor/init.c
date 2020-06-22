/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 02:54:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "game/entities/editor/component_entity.h"
#include "game/entities/editor/editor_camera_entity.h"
#include "game/entities/editor/ghost_segment_component_entity.h"
#include "engine/error.h"
#include "engine/game.h"

static void	add_modules(t_new_editor_scene *const self)
{
	(void)self;
}

static void	add_entities(t_new_editor_scene *const self,
				const t_new_editor_scene_args *const args)
{
	if (!self->super.module.has_error)
		self->camera_ref = (t_editor_camera_entity*)entity_list_add_entity(
			&self->super.entities,
			editor_camera_entity(args->screen->size.y * 0.2f));
}

#include <stdio.h>

t_result	init_new_editor_scene(t_new_editor_scene *const self,
				const t_new_editor_scene_args *const args)
{
	if (init_scene(&self->super, "Editor", new_editor_scene_update,
		new_editor_scene_render) == ERROR)
	{
		return (throw_result_str("init_new_editor_scene()",
			"failed to init scene"));
	}
	init_list_head(&self->entities);
	init_list_head(&self->blocks);
	add_modules(self);
	add_entities(self, args);
	self->screen_ref = args->screen;
	if (self->super.module.has_error)
	{
		destroy_new_editor_scene(self);
		return (throw_result_str("init_new_editor_scene()",
			"failed to create scene"));
	}
	return (OK);
}