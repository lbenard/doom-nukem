/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:19:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 19:34:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/game.h"
#include "game/entities/weapon_entity.h"
#include "game/scenes/raycasting_scene.h"

t_result	init_weapon_entity(t_weapon_entity *const self,
				const t_weapon_entity_args *const args)
{
	if (static_module_create(self,
		sprite_entity(ft_vec3f(0.0f, 0.0f, 0.0f),
			args->icon_path, args->ctx)) == ERROR)
	{
		return (throw_result_str("init_weapon_entity()",
			"failed to create parent class"));
	}
	module_add(&self->super.super.module, &self->hud,
		frame(args->ctx->window_ref->size, ft_rgba(0, 0, 0, 0)));
	if (self->super.super.module.has_error)
	{
		destroy_weapon_entity(self);
		return (throw_result_str("init_weapon_entity()",
			"failed to create hud frame"));
	}
	if (!entity_list_add_entity_ref(&args->ctx->weapon_entities,
		(t_entity*)self))
	{
		destroy_weapon_entity(self);
		return (throw_result_str("init_weapon_entity()",
			"failed to add weapon to list"));
	}
	self->hud_ref = NULL;
	self->sound_ref = NULL;
	self->first_render = TRUE;
	self->specs = args->specs;
	self->last_shot = 0.0;
	self->loading = FALSE;
	self->reloading = FALSE;
	self->shooting = FALSE;
	self->trigger_reloading = FALSE;
	self->just_shooted = FALSE;
	self->just_reloaded = FALSE;
	self->load_start = 0.0;
	self->reload_start = 0.0;
	self->shoot_start = 0.0;
	return (OK);
}