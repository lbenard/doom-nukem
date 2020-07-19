/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

t_result	init_onepunchman_entity(t_onepunchman_entity *const self,
				const t_onepunchman_entity_args *const args)
{
	t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(args->pos,
			&raycasting->ss,
			raycasting->player_ref,
			100.0f,
			10.0f,
			"One Punch Man")) == ERROR)
	{
		return (throw_result_str("init_onepunchman_entity()",
			"failed to create monster entity"));
	}
	self->super.super.super.vtable.update = onepunchman_entity_update;
	return (OK);
}