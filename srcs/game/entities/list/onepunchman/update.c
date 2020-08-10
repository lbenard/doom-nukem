/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/09 14:19:07 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include <math.h>

void			onepunchman_entity_update(t_onepunchman_entity *const self)
{
	t_vec3f	position;
	t_vec2f	next_pos;
	t_vec3f	difference;
	t_vec3f	direction;
	float	distance;
	t_vec3f	player_pos;

	monster_entity_update(&self->super);
	player_pos = self->super.super.player_ref->super.transform.position;
	position = self->super.super.super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
    player_pos.y - position.y,
    player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z; 
	if (distance < 30)
	{
		if (self->super.is_star == FALSE)
		{
			init_astar(&self->super.a_star, self->super.super.player_ref->map_ref,
				self->super.super.super, self->super.super.player_ref->super);
			self->super.is_star = TRUE;
		}
		if (((ssize_t)self->super.super.super.transform.position.x != self->super.a_star.next_pos.pos.x) || 
				((ssize_t)self->super.super.super.transform.position.y != self->super.a_star.next_pos.pos.y))
		{
			self->super.animation.speed = 1.0f;
			position = self->super.super.super.transform.position;
			next_pos.x = self->super.a_star.next_pos.pos.x;
			next_pos.y = self->super.a_star.next_pos.pos.y;
			next_pos.x += 0.5f;
			next_pos.y += 0.5f;
			difference = ft_vec3f((float)next_pos.x - position.x,
				(float)next_pos.y - position.y,
		 		0.0f);
			direction = difference;
			direction = vec3f_normalize(direction);
			direction = vec3f_scalar(direction, 2.0f);
			direction = vec3f_scalar(direction, get_last_delta());
			self->super.super.super.transform.position.x += direction.x;
			self->super.super.super.transform.position.y += direction.y;
			self->super.super.super.transform.position.z += direction.z;
			self->super.super.super.transform.direction = vec3f_normalize(direction);
			// animation_update(&self->animation, self->spritesheet_ref);
			init_astar(&self->super.a_star,
				self->super.player_ref->map_ref,
				self->super.super.super,
				self->super.player_ref->super);
		}
		else
		{
			if (self->super.player_ref->is_taking_damage == FALSE && distance < 1.5f)
			{
				player_entity_take_damage(self->super.player_ref, self->super.damage);
				self->super.player_ref->is_taking_damage = TRUE;
			}
			self->super.player_ref->is_taking_damage = FALSE;
			self->super.animation.speed = 0;
			init_astar(&self->super.a_star,
				self->super.player_ref->map_ref,
				self->super.super.super,
				self->super.player_ref->super);
		}
	}
	else
		self->super.animation.speed = 0.0f;
}
