/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 21:21:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

static void	init_vars(t_ghast_entity *const self)
{
	self->super.super.super.vtable.update = ghast_entity_update;
	self->shoot_time = 2.2f;
	self->last_shot_time = 0.0;
	self->just_shoot = FALSE;
	self->move_side = FALSE;
	self->last_pos.x = 0.0f;
	self->last_pos.y = 0.0f;
	self->last_pos.z = 0.0f;
	self->side_move.x = 0.0f;
	self->side_move.y = 0.0f;
	self->side_move.z = 0.0f;
	self->super.distance_agro = 40;
	self->super.max_distance_agro = 60;
}

t_result	init_ghast_entity(t_ghast_entity *const self,
				const t_ghast_entity_args *const args)
{
	t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				100.0f,
				0.0f,
				"Ghast"),
			&raycasting->assets.ghast_spritesheet,
			raycasting)) == ERROR)
	{
		return (throw_result_str("init_ghast_entity()",
			"failed to create monster entity"));
	}
	init_vars(self);
	return (OK);
}
