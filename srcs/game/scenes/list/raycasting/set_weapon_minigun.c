/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weapon_minigun.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:15:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 22:19:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_set_weapon_minigun(t_raycasting_scene *const self)
{
	self->weapon.name = "Minigun";
	self->weapon.ammo = 100;
	self->weapon.clip = 12;
	self->weapon.clip_size = 12;
	self->weapon.damage = 5.0f;
	self->weapon.shoot_time = 1.0f / 20.0f;
	self->weapon.last_shot = get_wall_time();
}
