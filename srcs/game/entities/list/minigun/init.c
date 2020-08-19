/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:32:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:37:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minigun_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

static t_result	init_minigun_entity2(t_minigun_entity *const self,
				t_minigun_entity_args *const args,
				t_raycasting_scene *ctx)
{
	if (self->super.super.super.module.has_error)
	{
		destroy_minigun_entity(self);
		return (throw_result_str("init_minigun_entity()",
			"failed to create minigun animation"));
	}
	self->super.super.super.vtable.update = minigun_entity_update;
	self->super.hud_ref = &ctx->assets.minigun_spritesheet;
	self->super.super.super.transform.position.x = args->pos.x;
	self->super.super.super.transform.position.y = args->pos.y;
	self->super.super.super.transform.position.z = 0.0f;
	self->super.super.super.transform.scale.x = 0.5f;
	self->super.super.super.transform.scale.y = 0.5f;
	return (OK);
}

t_result		init_minigun_entity(t_minigun_entity *const self,
				t_minigun_entity_args *const args)
{
	t_raycasting_scene	*ctx;
	t_weapon_specs		minigun_specs;

	ctx = (t_raycasting_scene*)args->scene;
	minigun_specs = ft_weapon_specs_default();
	minigun_specs.clip_size = 0;
	minigun_specs.clip = 9999;
	minigun_specs.damage = 5.0f;
	minigun_specs.name = "Minigun";
	minigun_specs.shoot_time = 1.0f / 20.0f;
	minigun_specs.loading_time = 1.5f;
	if (static_module_create(self,
		weapon_entity(&ctx->assets.minigun_spritesheet,
			"resources/sprites/minigun_sprite.bmp",
			minigun_specs, ctx)) == ERROR)
	{
		return (throw_result_str("init_minigun_entity()",
			"failed to create parent class"));
	}
	module_add(&self->super.super.super.module, &self->animation,
		animation(0, 4, 0.0f));
	return (init_minigun_entity2(self, args, ctx));
}
