/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:57:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 22:35:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "game/entities/weapon_entity.h"
#include "game/scenes/raycasting_scene.h"

void	weapon_entity_update(t_weapon_entity *const self)
{
	const t_raycasting_scene	*ctx;

	sprite_entity_update(&self->super);
	ctx = (t_raycasting_scene*)game_singleton()->scene;
	self->is_picked = ctx->entities.weapon_ref == self;
	if (self->is_picked)
		self->super.is_visible = FALSE;
}
