/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_stats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:52:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/07 01:06:10 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

t_monster_stats	ft_monster_stats(const t_vec2f pos,
					const float health,
					const float damage,
					const char *name)
{
	t_monster_stats	ret;

	ret.pos = pos;
	ret.health = health;
	ret.damage = damage;
	ret.name = name;
	return (ret);
}
