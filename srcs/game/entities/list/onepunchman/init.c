/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/21 03:46:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

t_result	init_onepunchman_entity(t_onepunchman_entity *const self,
				const t_onepunchman_entity_args *const args)
{
	const t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				100.0f,
				10.0f,
				"Weird Alien"),
			&raycasting->ss,
			raycasting->player_ref,
			&raycasting->window_ref->frame)) == ERROR)
	{
		return (throw_result_str("init_onepunchman_entity()",
			"failed to create monster entity"));
	}
	return (OK);
}