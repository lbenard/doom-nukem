/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:46:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/17 20:08:48 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"
#include "maths/maths.h"

void	raycasting_scene_weapon_use(t_raycasting_scene *const self)
{
	double	time;
	double	next_possible_shot;

	if (self->entities.weapon_ref)
	{
		time = get_wall_time();
		if (self->entities.weapon_ref->load_start == 0.0)
		{
			self->entities.weapon_ref->load_start = time;
			self->entities.weapon_ref->shoot_start =
				self->entities.weapon_ref->load_start
				+ self->entities.weapon_ref->specs.loading_time;
		}
		self->entities.weapon_ref->loading =
			!self->entities.weapon_ref->shooting;
		next_possible_shot = ft_dmax(self->entities.weapon_ref->last_shot
			+ self->entities.weapon_ref->specs.shoot_time,
			self->entities.weapon_ref->shoot_start);
		if (next_possible_shot > time)
			return ;
		if (raycasting_scene_weapon_shoot(self, 1))
			self->entities.weapon_ref->last_shot = time;
	}
}
