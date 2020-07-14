/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 21:50:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/error.h"
#include "game/entities/player_entity.h"
#include "game/events/events.h"

/*
** Gloomy magic bit of code
*/
static t_bool	is_player_immured(const t_vec2f position,
					const t_map *const map)
{
	return (map->map[(int)position.x
		+ (int)position.y * map->size.x].texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)position.y * map->size.x].texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)(position.y + 0.1) * map->size.x].texture_ref ||
		map->map[(int)position.x
		+ (int)position.y * map->size.x].texture_ref ||
		map->map[(int)position.x
		+ (int)(position.y + 0.1) * map->size.x].texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)(position.y + 0.1) * map->size.x].texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)position.y * map->size.x].texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)(position.y - 0.1) * map->size.x].texture_ref ||
		map->map[(int)position.x
		+ (int)(position.y - 0.1) * map->size.x].texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)(position.y - 0.1) * map->size.x].texture_ref);
}

t_result		init_player_entity(t_player_entity *const self,
					const t_player_entity_args *const args)
{
	init_entity_default(&self->super, entity_vtable(player_entity_update));
	self->velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	self->is_moving = FALSE;
	self->map_ref = args->map;
	self->speed = 2.0f;
	self->super.transform.position.x = args->map->spawn.x;
	self->super.transform.position.y = args->map->spawn.y;
	if (is_player_immured(vec3f_to_vec2f(self->super.transform.position),
		self->map_ref))
	{
		destroy_player_entity(self);
		return (throw_result_str("init_player_entity()",
			"player is immured"));
	}
	self->forward = input_get_id(&game_singleton()->input, "Forward");
	self->backward = input_get_id(&game_singleton()->input, "Backward");
	self->left = input_get_id(&game_singleton()->input, "Left");
	self->right = input_get_id(&game_singleton()->input, "Right");
	self->turn_left = input_get_id(&game_singleton()->input, "CameraLeft");
	self->turn_right = input_get_id(&game_singleton()->input, "CameraRight");
	self->camera_up = input_get_id(&game_singleton()->input, "CameraUp");
	self->camera_down = input_get_id(&game_singleton()->input, "CameraDown");
	self->sprint = input_get_id(&game_singleton()->input, "Sprint");
	if (self->super.module.has_error)
	{
		destroy_player_entity(self);
		return (throw_result_str("init_player_entity()",
			"failed while creating new player entity"));
	}
	return (OK);
}
