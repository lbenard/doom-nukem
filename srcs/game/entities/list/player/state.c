/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:45:59 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/14 20:58:35 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"
#include "engine/delta.h"

static void	player_gravity(t_player_entity *const self)
{
	float	weight;
	float	g;

	weight = 0.07f;
	g = 7.5f * get_last_delta();
	if (!self->is_flying)
	{
		self->super.transform.direction.z -= weight * g;
		self->super.transform.position.z += self->super.transform.direction.z;
		if (self->super.transform.position.z <= 0.0f)
		{
			self->super.transform.position.z = 0.0f;
			self->super.transform.direction.z = 0.0f;
			self->is_jumping = FALSE;
			self->just_jump = FALSE;
		}
	}
}

void		flying_player_state(t_player_entity *const self)
{
	if (self->is_flying)
	{
		self->super.transform.position.z += 3.0f
			* input_get(&game_singleton()->input, self->jump)
			* get_last_delta();
		self->super.transform.position.z -= 3.0f
			* input_get(&game_singleton()->input, self->crouch)
			* get_last_delta();
	}
	else
	{
		player_gravity(self);
		if (input_get(&game_singleton()->input, self->jump) > 0.0f)
			jump(self);
		if (input_get(&game_singleton()->input, self->crouch) > 0.0f)
			crouch(self);
		if (self->is_crouching == TRUE &&
			input_get(&game_singleton()->input, self->crouch) <= 0.0f)
		{
			self->is_crouching = FALSE;
			self->super.transform.position.z = 0.0f;
		}
	}
}

void		moving_player_state(t_player_entity *const self)
{
	if (self->is_moving)
	{
		self->velocity = vec3f_normalize(self->velocity);
		self->velocity = vec3f_scalar(self->velocity, get_last_delta());
		self->velocity = vec3f_scalar(self->velocity, self->speed);
		if (self->is_crouching)
			self->velocity = vec3f_scalar(self->velocity, 0.5f);
		if (input_get(&game_singleton()->input, self->sprint))
			self->velocity = vec3f_scalar(self->velocity, 2.0f);
	}
	else
		self->velocity = vec3f_scalar(self->velocity, 0.8f);
}
