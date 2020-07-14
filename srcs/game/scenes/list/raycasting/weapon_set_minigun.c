/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_set_minigun.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:15:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/14 19:58:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_weapon_set_minigun(t_raycasting_scene *const self)
{
	self->weapon.weapon.name = "Minigun";
	self->weapon.weapon.ammo = 0;
	self->weapon.weapon.clip = 5000;
	self->weapon.weapon.clip_size = 5000;
	self->weapon.weapon.damage = 5.0f;
	self->weapon.weapon.shoot_time = 1.0f / 20.0f;
	self->weapon.weapon.last_shot = 0.0f;
}
