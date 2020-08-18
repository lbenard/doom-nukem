/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:20:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 23:11:08 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"

void	init_raycasting_scene_vars(t_raycasting_scene *const self,
			t_raycasting_scene_args *const args)
{
	self->path = args->path;
	self->death_time = 0.0f;
	self->fov = 90.0f * M_PI / 180.0f;
	self->window_ref = args->window;
	self->entities.weapon_ref = NULL;
	self->weapon.ammo = 20;
	self->weapon.last_shot = 0.0;
	self->weapon.nearest_weapon = NULL;
	self->tooltips.ending_triggered = FALSE;
}
