/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weapon_pistol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:46:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 19:08:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

void	raycasting_scene_set_weapon_pistol(t_raycasting_scene *const self)
{
	self->weapon.name = "Pistol";
	self->weapon.ammo = 100;
	self->weapon.clip = 12;
	self->weapon.clip_size = 12;
	self->weapon.damage = 10.0f;
	self->weapon.shoot_time = 0.2f;
	self->weapon.last_shot = get_wall_time();
}
