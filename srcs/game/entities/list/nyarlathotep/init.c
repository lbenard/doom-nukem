/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:23:22 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/07 01:59:05 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

t_result	init_nyarlathotep_entity(t_nyarlathotep_entity *const self,
				const t_nyarlathotep_entity_args *const args)
{
	t_raycasting_scene	*scene;

	scene = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				200.0f,
				10.0f,
				"Nyarlathotep"),
			&scene->nyarlathotep_spritesheet,
			scene)) == ERROR)
	{
		return (throw_result_str("init_nyarlathotep_entity()",
			"failed to create monster entity"));
	}
	self->super.super.super.vtable.update = nyarlathotep_entity_update;
	return (OK);
}