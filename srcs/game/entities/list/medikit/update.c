/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:44:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 22:43:52 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/medikit_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "maths/maths.h"

void	medikit_entity_update(t_medikit_entity *const self)
{
	float	heal;

	heal = self->super.ctx->entities.player_ref->max_health / 4;
	sprite_entity_update(&self->super);
	if (vec3f_squared_distance(self->super.super.transform.position,
		self->super.ctx->entities.player_ref->super.transform.position) < 1.0f
		&& self->super.ctx->entities.player_ref->health <
		self->super.ctx->entities.player_ref->max_health)
	{
		self->super.ctx->entities.player_ref->health = ft_fmin(
			self->super.ctx->entities.player_ref->health += heal,
			self->super.ctx->entities.player_ref->max_health);
		entity_list_remove(&self->super.ctx->super.entities,
			(t_entity*)self);
		return ;
	}
}
