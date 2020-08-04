/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:46:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 17:15:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_weapon_use(t_raycasting_scene *const self)
{
	double	time;
	double	next_possible_shot;

	if (self->weapon_ref)
	{
		time = get_wall_time();
		next_possible_shot = self->weapon_ref->last_shot
			+ self->weapon_ref->specs.shoot_time;
		if (next_possible_shot > time)
			return ;
		if (self->weapon.reloading == FALSE)
			if (raycasting_scene_weapon_shoot(self, 1))
				self->weapon.weapon.last_shot = time;
	}
}
