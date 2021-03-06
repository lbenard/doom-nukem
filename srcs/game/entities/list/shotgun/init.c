/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:32:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:39:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/shotgun_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

static t_result	init_shotgun_entity2(t_shotgun_entity *const self,
					t_shotgun_entity_args *const args,
					t_raycasting_scene *ctx)
{
	if (self->super.super.super.module.has_error)
	{
		destroy_shotgun_entity(self);
		return (throw_result_str("init_shotgun_entity()",
			"failed to create shotgun animation"));
	}
	self->super.super.super.vtable.update = shotgun_entity_update;
	self->super.hud_ref = &ctx->assets.shotgun_spritesheet;
	self->super.sound_ref = &ctx->assets.shotgun_sound;
	self->super.super.super.transform.position.x = args->pos.x;
	self->super.super.super.transform.position.y = args->pos.y;
	self->super.super.super.transform.position.z = 0.0f;
	self->super.super.super.transform.scale.x = 0.4f;
	self->super.super.super.transform.scale.y = 0.4f;
	return (OK);
}

t_result		init_shotgun_entity(t_shotgun_entity *const self,
					t_shotgun_entity_args *const args)
{
	t_raycasting_scene	*ctx;
	t_weapon_specs		shotgun_specs;

	ctx = (t_raycasting_scene*)args->scene;
	shotgun_specs = ft_weapon_specs_default();
	shotgun_specs.clip_size = 2;
	shotgun_specs.clip = 2;
	shotgun_specs.damage = 60.0f;
	shotgun_specs.name = "Shotgun";
	shotgun_specs.shoot_time = 0.4f;
	shotgun_specs.decay = 0.3f;
	if (static_module_create(self,
		weapon_entity(&ctx->assets.shotgun_spritesheet,
			"resources/sprites/shotgun-sprite.bmp",
			shotgun_specs, ctx)) == ERROR)
	{
		return (throw_result_str("init_shotgun_entity()",
			"failed to create parent class"));
	}
	module_add(&self->super.super.super.module, &self->animation,
		animation(0, 5, 0.0f));
	return (init_shotgun_entity2(self, args, ctx));
}
