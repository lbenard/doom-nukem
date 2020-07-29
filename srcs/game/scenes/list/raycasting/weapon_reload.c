/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_reload.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:30:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/29 15:52:09 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/str.h"

void	raycasting_scene_weapon_reload(t_raycasting_scene *const self)
{
	size_t	bullet_needed;
 
    bullet_needed = self->weapon.weapon.clip_size - self->weapon.weapon.clip;
    if (bullet_needed == 0)
        return ;
    if (self->weapon.weapon.ammo == 0)
        return ;
    if (bullet_needed > self->weapon.weapon.ammo)
    {
        self->weapon.weapon.clip += self->weapon.weapon.ammo;
        self->weapon.weapon.ammo = 0;
        return ;
    }
    self->weapon.weapon.clip += bullet_needed;
    self->weapon.weapon.ammo -= bullet_needed;
	self->weapon.just_reloaded = TRUE;
    if (ft_strcmp(self->weapon.weapon.name, "Shotgun") == 0)
        self->weapon.shotgun = bullet_needed;
    return ;
}
