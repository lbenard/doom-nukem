/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_reload.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:30:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 03:27:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/str.h"

void	raycasting_scene_weapon_reload(t_raycasting_scene *const self)
{
	size_t	bullet_needed;

	if (self->entities.weapon_ref
		&& !self->entities.weapon_ref->reloading
		&& !self->entities.weapon_ref->shooting)
	{
		bullet_needed = self->entities.weapon_ref->specs.clip_size
			- self->entities.weapon_ref->specs.clip;
		if (bullet_needed == 0)
			return ;
		if (self->weapon.ammo == 0)
			return ;
		if (bullet_needed > self->weapon.ammo)
		{
			self->entities.weapon_ref->specs.clip += self->weapon.ammo;
			self->weapon.ammo = 0;
			return ;
		}
		self->entities.weapon_ref->specs.clip += bullet_needed;
		self->weapon.ammo -= bullet_needed;
		self->entities.weapon_ref->just_reloaded = TRUE;
		return ;
	}
}
