/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_set_pistol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:46:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/13 20:59:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_weapon_set_pistol(t_raycasting_scene *const self)
{
	self->weapon.weapon.name = "Pistol";
	self->weapon.weapon.ammo = 100;
	self->weapon.weapon.clip = 12;
	self->weapon.weapon.clip_size = 12;
	self->weapon.weapon.damage = 10.0f;
	self->weapon.weapon.shoot_time = 0.2f;
	self->weapon.weapon.last_shot = 0.0f;
}
