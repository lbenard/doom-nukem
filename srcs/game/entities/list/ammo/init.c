/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:33:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/17 00:18:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/ammo_entity.h"

t_result	init_ammo_entity(t_ammo_entity *const self,
				t_ammo_entity_args *const args)
{
	t_raycasting_scene	*ctx;

	ctx = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		sprite_entity_from(ft_vec3f(args->pos.x, args->pos.y, 0.0f),
			&ctx->assets.ammo_sprite,
			ctx)) == ERROR)
	{
		return (throw_result_str("init_ammo_entity()",
			"failed to init parent class"));
	}
	if (!entity_list_add_entity_ref(&ctx->ammo_entities, (t_entity*)self))
	{
		destroy_ammo_entity(self);
		return (throw_result_str("init_ammo_entity()",
			"failed to add ammo entity to list"));
	}
	self->super.super.vtable.update = ammo_entity_update;
	self->super.super.transform.scale.x = 0.2f;
	self->super.super.transform.scale.y = 0.2f;
	return (OK);
}
