/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:48:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 18:28:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weird_alien_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "game/game.h"
#include "engine/error.h"

t_result	init_weird_alien_entity(t_weird_alien_entity *const self,
				const t_weird_alien_entity_args *const args)
{
	t_raycasting_scene	*raycasting;

	raycasting = (t_raycasting_scene*)args->scene;
	if (static_module_create(self,
		monster_entity(
			ft_monster_stats(args->pos,
				100.0f,
				10.0f,
				"Weird Alien"),
			&raycasting->assets.alien_spritesheet,
			raycasting)) == ERROR)
	{
		return (throw_result_str("init_weird_alien_entity()",
			"failed to create monster entity"));
	}
	return (OK);
}