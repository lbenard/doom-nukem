/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:32:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/20 18:09:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/pistol_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

static t_result	init_pistol_entity2(t_pistol_entity *const self,
				t_pistol_entity_args *const args,
				t_raycasting_scene *ctx)
{
	module_add(&self->super.super.super.module, &self->animation,
		animation(0, 4, 0.0f));
	if (self->super.super.super.module.has_error)
	{
		destroy_pistol_entity(self);
		return (throw_result_str("init_pistol_entity()",
			"failed to create pistol animation"));
	}
	self->super.super.super.vtable.update = pistol_entity_update;
	self->super.hud_ref = &ctx->assets.pistol_spritesheet;
	self->super.super.super.transform.position.x = args->pos.x;
	self->super.super.super.transform.position.y = args->pos.y;
	self->super.super.super.transform.position.z = 0.0f;
	self->super.super.super.transform.scale.x = 0.2f;
	self->super.super.super.transform.scale.y = 0.2f;
	return (OK);
}

t_result		init_pistol_entity(t_pistol_entity *const self,
					t_pistol_entity_args *const args)
{
	t_raycasting_scene	*ctx;
	t_weapon_specs		pistol_specs;

	ctx = (t_raycasting_scene*)args->scene;
	pistol_specs = ft_weapon_specs_default();
	pistol_specs.clip_size = 12;
	pistol_specs.clip = 12;
	pistol_specs.damage = 10.0f;
	pistol_specs.name = "Pistol";
	pistol_specs.shoot_time = 0.4f;
	if (static_module_create(self,
		weapon_entity(&ctx->assets.pistol_spritesheet,
			"resources/sprites/pistol-sprite.bmp",
			pistol_specs, ctx)) == ERROR)
	{
		return (throw_result_str("init_pistol_entity()",
			"failed to create parent class"));
	}
	return (init_pistol_entity2(self, args, ctx));
}
