/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:39:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 20:32:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "game/scenes/raycasting_scene.h"

void	destroy_monster_entity(t_monster_entity *const self)
{
	t_raycasting_scene	*ctx;

	ctx = (t_raycasting_scene*)game_singleton()->scene;
	destroy_sprite_entity(&self->super);
	entity_list_remove(&ctx->monster_entities, (t_entity*)self);
}