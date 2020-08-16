/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 16:32:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include <math.h>

void			rage_opm(t_onepunchman_entity *const self)
{
	if (self->count_fireball >= 5)
	{
		if (get_wall_time() - self->last_shot > 5.0)
			self->count_fireball = 0;
	}
	if (self->count_fireball < 5 && get_wall_time() - self->last_shot > 0.2f)
	{
		go_fireball(&self->super);
		self->last_shot = get_wall_time();
		self->count_fireball++;
	}
}

void			onepunchman_entity_update(t_onepunchman_entity *const self)
{
	float	distance;

	monster_entity_update(&self->super);
	if ((distance = distance_monster_player(&self->super)) <
		self->super.distance_agro)
	{
		self->super.agro = TRUE;
		self->super.animation.speed = 0.4;
		self->is_moving = TRUE;
		a_star_attack(&self->super, distance, 2.0);
		if (self->super.health <= self->super.full_health / 2)
			rage_opm(self);
	}
	else
	{
		self->super.agro = FALSE;
		self->super.animation.speed = 0.0f;
		self->super.animation.iter = 0;
	}
	update_agro_distance(&self->super);
}
