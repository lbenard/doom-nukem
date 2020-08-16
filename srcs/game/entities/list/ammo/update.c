/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:44:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/17 00:26:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ammo_entity.h"
#include "game/scenes/raycasting_scene.h"

void	ammo_entity_update(t_ammo_entity *const self)
{
	sprite_entity_update(&self->super);
	if (vec3f_squared_distance(self->super.super.transform.position,
		self->super.ctx->entities.player_ref->super.transform.position) < 1.0f)
	{
		self->super.ctx->weapon.ammo += 30;
		self->super.ctx->entities.weapon_ref->first_render = TRUE;
		entity_list_remove(&self->super.ctx->super.entities,
			(t_entity*)self);
		return ;
	}
}
