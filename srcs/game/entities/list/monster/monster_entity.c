/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:14:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/19 21:28:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

t_constructor	monster_entity(const float health,
					const int damage,
					const t_vec2f pos,
					char *const path)
{
	static t_monster_entity_args	args;

	args.health = health;
	args.damage = damage;
	args.pos = pos;
	args.path = path;
	return (ft_constructor(init_monster_entity,
		destroy_monster_entity,
		sizeof(t_monster_entity),
		&args
	));
}
