/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/14 20:42:32 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
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

void			init_vars(t_player_entity *const self,
					const t_player_entity_args *const args)
{
	self->velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	self->is_moving = FALSE;
	self->is_flying = FALSE;
	self->map_ref = args->map;
	self->speed = 3.0f;
	self->fov = args->fov;
	self->forward = input_get_id(&game_singleton()->input, "Forward");
	self->backward = input_get_id(&game_singleton()->input, "Backward");
	self->left = input_get_id(&game_singleton()->input, "Left");
	self->right = input_get_id(&game_singleton()->input, "Right");
	self->turn_left = input_get_id(&game_singleton()->input, "CameraLeft");
	self->turn_right = input_get_id(&game_singleton()->input, "CameraRight");
	self->camera_up = input_get_id(&game_singleton()->input, "CameraUp");
	self->camera_down = input_get_id(&game_singleton()->input, "CameraDown");
	self->sprint = input_get_id(&game_singleton()->input, "Sprint");
	self->toggle_flight = input_get_id(&game_singleton()->input,
		"ToggleFlight");
	self->jump = input_get_id(&game_singleton()->input, "Jump");
	self->crouch = input_get_id(&game_singleton()->input, "Crouch");
	self->is_crouching = FALSE;
	self->health = 150.0f;
	self->is_taking_damage = FALSE;
	self->is_dead = FALSE;
	self->is_jumping = FALSE;
	self->just_jump = FALSE;
}

t_result		init_player_entity(t_player_entity *const self,
					const t_player_entity_args *const args)
{
	float	rot_sin;
	float	rot_cos;

	init_entity_default(&self->super, entity_vtable(player_entity_update));
	init_vars(self, args);
	rot_sin = sin(self->super.transform.rotation.y);
	rot_cos = cos(self->super.transform.rotation.y);
	self->dir = ft_vec2f(rot_cos, rot_sin);
	self->plane = vec2f_scalar(ft_vec2f(-rot_sin, rot_cos), self->fov);
	self->super.transform.position.x = args->map->spawn.x;
	self->super.transform.position.y = args->map->spawn.y;
	if (is_player_immured(vec3f_to_vec2f(self->super.transform.position),
		self->map_ref))
	{
		destroy_player_entity(self);
		return (throw_result_str("init_player_entity()",
			"player is immured"));
	}
	if (self->super.module.has_error)
	{
		destroy_player_entity(self);
		return (throw_result_str("init_player_entity()",
			"failed while creating new player entity"));
	}
	return (OK);
}
