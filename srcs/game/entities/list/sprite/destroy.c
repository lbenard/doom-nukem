/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:42:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 03:02:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "game/scenes/raycasting_scene.h"

void	destroy_sprite_entity(t_sprite_entity *const self)
{
	entity_list_remove(&self->ctx->sprite_entities, &self->super);
	destroy_module(&self->super.module);
}
