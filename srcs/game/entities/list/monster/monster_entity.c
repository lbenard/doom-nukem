/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:14:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 03:44:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

t_constructor	monster_entity(const t_vec2f pos,
					const t_spritesheet *const spritesheet_ref,
					const t_player_entity *const player_ref,
					const float health,
					const float damage,
					const char *const name)
{
	static t_monster_entity_args	args;

	args.pos = pos;
	args.spritesheet_ref = spritesheet_ref;
	args.player_ref = player_ref;
	args.health = health;
	args.damage = damage;
	args.name = name;
	return (ft_constructor(init_monster_entity,
		destroy_monster_entity,
		sizeof(t_monster_entity),
		&args
	));
}
