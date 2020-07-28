/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_damage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:15:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/28 23:15:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

void	player_entity_take_damage(t_player_entity *self, int damage)
{
	if (self->health - damage < 0.0f)
		self->health = 0.0f;
	else
		self->health -= damage;
}
