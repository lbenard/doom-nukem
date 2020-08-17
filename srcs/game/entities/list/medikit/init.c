/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:33:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 00:24:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/medikit_entity.h"

t_result	init_medikit_entity(t_medikit_entity *const self,
				t_medikit_entity_args *const args)
{
	t_raycasting_scene	*ctx;

	ctx = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		sprite_entity_from(ft_vec3f(args->pos.x, args->pos.y, 0.0f),
			&ctx->assets.medikit_sprite,
			ctx)) == ERROR)
	{
		return (throw_result_str("init_medikit_entity()",
			"failed to init parent class"));
	}
	self->super.super.vtable.update = medikit_entity_update;
	self->super.super.transform.scale.x = 0.2f;
	self->super.super.transform.scale.y = 0.2f;
	return (OK);
}
