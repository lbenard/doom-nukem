/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:23:22 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 16:23:43 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

static void	init_vars(t_nyarlathotep_entity *const self)
{
	self->super.super.super.vtable.update = nyarlathotep_entity_update;
	self->end_circle = FALSE;
	self->end_move = FALSE;
	self->is_moving = FALSE;
	self->stuck = FALSE;
	self->unstuck_time = 0.0;
	self->super.distance_agro = 60;
	self->super.max_distance_agro = 80;
	self->angle = 0;
}

t_result	init_nyarlathotep_entity(t_nyarlathotep_entity *const self,
				const t_nyarlathotep_entity_args *const args)
{
	t_raycasting_scene	*scene;

	scene = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				200.0f,
				5.0f,
				"Nyarlathotep"),
			&scene->nyarlathotep_spritesheet,
			scene)) == ERROR)
	{
		return (throw_result_str("init_nyarlathotep_entity()",
			"failed to create monster entity"));
	}
	init_vars(self);
	return (OK);
}
