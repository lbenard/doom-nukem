/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:44:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:52:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/ammo_entity.h"

void	destroy_ammo_entity(t_ammo_entity *const self)
{
	entity_list_remove(&self->super.ctx->ammo_entities, &self->super.super);
	destroy_sprite_entity(&self->super);
}
