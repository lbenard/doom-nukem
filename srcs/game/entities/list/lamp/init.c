/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:33:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 04:57:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/lamp_entity.h"

t_result	init_lamp_entity(t_lamp_entity *const self,
				t_lamp_entity_args *const args)
{
	t_raycasting_scene	*ctx;

	ctx = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		sprite_entity_from(ft_vec3f(args->pos.x, args->pos.y, 0.6f),
			&ctx->assets.lamp_sprite,
			ctx)) == ERROR)
	{
		return (throw_result_str("init_lamp_entity()",
			"failed to init parent class"));
	}
	if (!entity_list_add_entity_ref(&ctx->light_entities, (t_entity*)self))
	{
		destroy_lamp_entity(self);
		return (throw_result_str("init_lamp_entity()",
			"failed to add lamp to list"));
	}
	self->super.super.transform.scale.x = 0.4f;
	self->super.super.transform.scale.y = 0.4f;
	return (OK);
}
