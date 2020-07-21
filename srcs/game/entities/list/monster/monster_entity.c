/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:14:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/21 18:27:59 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

t_constructor	monster_entity(const t_monster_stats stats,
					const t_spritesheet *const spritesheet_ref,
					t_player_entity *player_ref,
					const t_frame *const frame_ref)
{
	static t_monster_entity_args	args;

	args.pos = stats.pos;
	args.health = stats.health;
	args.damage = stats.damage;
	args.name = stats.name;
	args.spritesheet_ref = spritesheet_ref;
	args.player_ref = player_ref;
	args.frame_ref = frame_ref;
	return (ft_constructor(init_monster_entity,
		destroy_monster_entity,
		sizeof(t_monster_entity),
		&args
	));
}
