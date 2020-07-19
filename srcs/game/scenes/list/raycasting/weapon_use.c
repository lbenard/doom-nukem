/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:46:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:25:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_weapon_use(t_raycasting_scene *const self)
{
	double	time;

	time = get_wall_time();
	if (self->weapon.weapon.last_shot + self->weapon.weapon.shoot_time > time)
		return ;
	if (raycasting_scene_weapon_shoot(self, 1))
		self->weapon.weapon.last_shot = time;
}
