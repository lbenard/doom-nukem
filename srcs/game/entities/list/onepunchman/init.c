/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 04:29:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

#include <stdio.h>

t_result	init_onepunchman_entity(t_onepunchman_entity *const self,
				const t_onepunchman_entity_args *const args)
{
	t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				500.0f,
				10000.0f,
				"One Punch Man"),
			&raycasting->assets.onepunchman_spritesheet,
			raycasting)) == ERROR)
	{
		return (throw_result_str("init_onepunchman_entity()",
			"failed to create monster entity"));
	}
	self->super.super.super.vtable.update = onepunchman_entity_update;
	self->super.super.super.transform.scale.x = 4.0f;
	self->super.super.super.transform.scale.y = 1.4f;
	return (OK);
}
