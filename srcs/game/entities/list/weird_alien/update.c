/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:17:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/entities/weird_alien_entity.h"
#include "engine/delta.h"

static void	weird_alien_entity_update2(t_weird_alien_entity *const self,
				t_vec3f difference,
				float distance,
				t_vec3f velocity)
{
	if (distance < 75)
	{
		self->super.animation.speed = 1.0f;
		velocity.x += difference.x;
		velocity.y += difference.y;
		velocity.z += difference.z;
	}
	else
		self->super.animation.speed = 0.0f;
	velocity = vec3f_normalize(velocity);
	velocity = vec3f_scalar(velocity, 2.0f);
	velocity = vec3f_scalar(velocity, get_last_delta());
	self->super.super.super.transform.position.x += velocity.x;
	self->super.super.super.transform.position.y += velocity.y;
	self->super.super.super.transform.position.z += velocity.z;
}

void		weird_alien_entity_update(t_weird_alien_entity *const self)
{
	t_vec3f	position;
	t_vec3f	player_pos;
	t_vec3f	difference;
	float	distance;
	t_vec3f	velocity;

	animation_update(&self->super.animation, self->super.spritesheet_ref);
	frame_layer_opaque(&self->super.super.texture,
		animation_current(&self->super.animation, self->super.spritesheet_ref),
		ft_isize(0, 0));
	position = self->super.super.super.transform.position;
	player_pos = self->super.player_ref->super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
		player_pos.y - position.y,
		player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z;
	velocity = ft_vec3f(cos(get_wall_time()), sin(get_wall_time()), 0.0f);
	weird_alien_entity_update2(self, difference, distance, velocity);
}
