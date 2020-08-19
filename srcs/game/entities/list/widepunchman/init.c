/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 01:12:53 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/widepunchman_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"
#include "engine/delta.h"

#include <stdio.h>

t_result	init_widepunchman_entity(t_widepunchman_entity *const self,
				const t_widepunchman_entity_args *const args)
{
	t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				5000.0f,
				10000.0f,
				"Wide Punch Man"),
			&raycasting->assets.widepunchman_spritesheet,
			raycasting)) == ERROR)
	{
		return (throw_result_str("init_widepunchman_entity()",
			"failed to create monster entity"));
	}
	self->super.super.super.vtable.update = widepunchman_entity_update;
	self->super.super.super.transform.scale.x = 6.0f;
	self->super.super.super.transform.scale.y = 1.4f;
	self->is_moving = FALSE;
	self->count_fireball = 0;
	self->last_shot = get_wall_time();
	self->super.max_distance_agro = 100;
	self->super.distance_agro = 80;
	self->speed = 2.0f;
	return (OK);
}
