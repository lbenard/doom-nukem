/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/28 18:30:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

#include <stdio.h>

t_result	init_ghast_entity(t_ghast_entity *const self,
				const t_ghast_entity_args *const args)
{
	const t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				100.0f,
				10.0f,
				"Ghast"),
			&raycasting->ghast_spritesheet,
			raycasting->player_ref,
			&raycasting->window_ref->frame)) == ERROR)
	{
		return (throw_result_str("init_ghast_entity()",
			"failed to create monster entity"));
	}
	self->super.super.super.vtable.update = ghast_entity_update;
	return (OK);
}