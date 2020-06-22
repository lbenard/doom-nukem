/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/19 21:28:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

void	monster_entity_update(t_sprite_entity *const self)
{
	t_monster_entity	*monster;

	monster = (t_monster_entity*)self;
	monster->health *= 0.99;
}
