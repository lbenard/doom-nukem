/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 16:30:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/error.h"
#include "game/entities/player_entity.h"
#include "game/events/events.h"

t_result	init_player_entity(t_player_entity *const self,
				const t_player_entity_args *const args)
{
	init_classic_entity_default(&self->super, player_entity_update);
	module_add(&self->super.module, &self->event_handler, event_handler(self));
	self->map_ref = args->map;
	self->speed = 2.0f;
	self->super.transform.position.x = args->map->spawn.x;
	self->super.transform.position.y = args->map->spawn.y;
	self->forward = input_get_id(&game_singleton()->input, "Forward");
	self->backward = input_get_id(&game_singleton()->input, "Backward");
	self->left = input_get_id(&game_singleton()->input, "Left");
	self->right = input_get_id(&game_singleton()->input, "Right");
	self->sprint = input_get_id(&game_singleton()->input, "Sprint");
	if (self->super.module.has_error)
	{
		destroy_player_entity(self);
		return (throw_result_str("new_player_entity()",
			"failed while creating new player entity"));
	}
	return (OK);
}
