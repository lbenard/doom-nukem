/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:14:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 17:36:24 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

t_constructor	monster_entity(const t_monster_stats stats,
					const t_spritesheet *const spritesheet_ref,
					t_raycasting_scene *const ctx)
{
	static t_monster_entity_args	args;

	args.pos = stats.pos;
	args.health = stats.health;
	args.damage = stats.damage;
	args.name = stats.name;
	args.spritesheet_ref = spritesheet_ref;
	args.ctx = ctx;
	return (ft_constructor(init_monster_entity,
		destroy_monster_entity,
		sizeof(t_monster_entity),
		&args));
}
