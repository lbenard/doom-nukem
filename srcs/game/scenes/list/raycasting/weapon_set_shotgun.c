/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_set_shotgun.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:07:13 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/29 16:21:14 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_weapon_set_shotgun(t_raycasting_scene *const self)
{
	self->weapon.weapon.name = "Shotgun";
	self->weapon.weapon.ammo = 36;
	self->weapon.weapon.clip = 2;
	self->weapon.weapon.clip_size = 2;
	self->weapon.weapon.damage = 60.0f;
	self->weapon.weapon.shoot_time = 0.4f;
	self->weapon.weapon.last_shot = 0.0f;
}