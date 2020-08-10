/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:39:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 17:02:20 by mribouch         ###   ########.fr       */
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
