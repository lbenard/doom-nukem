/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:19:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 03:27:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/game.h"
#include "game/entities/weapon_entity.h"
#include "game/scenes/raycasting_scene.h"

t_result	init_weapon_entity(t_weapon_entity *const self,
				const t_weapon_entity_args *const args)
{
	t_raycasting_scene	*ctx;

	ctx = (t_raycasting_scene*)game_singleton()->scene;
	if (static_module_create(self,
		sprite_entity_size(ft_vec3f(0.0f, 0.0f, 0.0f),
			args->spritesheet_ref->sprite_size,
			ctx->player_ref,
			&ctx->window_ref->frame)) == ERROR)
	{
		return (throw_result_str("init_weapon_entity()",
			"failed to create parent class"));
	}
	module_add(&self->super.super.module, &self->icon,
		frame_from_file(args->icon_path));
	if (self->super.super.module.has_error)
	{
		destroy_weapon_entity(self);
		return (throw_result_str("init_weapon_entity()",
			"failed to init weapon entity"));
	}
	self->specs = args->specs;
	self->last_shot = 0.0;
	self->loading = FALSE;
	self->reloading = FALSE;
	self->shooting = FALSE;
	self->just_shooted = FALSE;
	self->just_reloaded = FALSE;
	return (OK);
}