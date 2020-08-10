/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 17:01:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "engine/a_star.h"
#include "engine/delta.h"

static void	a_star_move(t_monster_entity *self, float speed)
{
	t_vec2f	next_pos;
	t_vec3f	position;
	t_vec3f	direction;

	position = self->super.super.transform.position;
	self->animation.speed = 0.6f;
	next_pos.x = self->a_star.next_pos.pos.x;
	next_pos.y = self->a_star.next_pos.pos.y;
	next_pos.x += 0.5f;
	next_pos.y += 0.5f;
	direction = ft_vec3f((float)next_pos.x - position.x,
		(float)next_pos.y - position.y, 0.0f);
	direction = vec3f_normalize(direction);
	self->super.super.transform.direction = direction;
	direction = vec3f_scalar(direction, get_last_delta() * speed);
	self->super.super.transform.position = vec3f_addition(
		self->super.super.transform.position, direction);
	init_astar(&self->a_star, self->player_ref->map_ref, self->super.super,
		self->player_ref->super);
}

void		a_star_attack(t_monster_entity *self, int distance, float speed)
{
	t_vec3f	position;

	position = self->super.super.transform.position;
	if (self->is_star == FALSE)
	{
		init_astar(&self->a_star, self->player_ref->map_ref,
			self->super.super, self->player_ref->super);
		self->is_star = TRUE;
	}
	if (((ssize_t)position.x != self->a_star.next_pos.pos.x) ||
			((ssize_t)position.y != self->a_star.next_pos.pos.y))
		a_star_move(self, speed);
	else
	{
		self->is_star = FALSE;
		if (self->player_ref->is_taking_damage == FALSE && distance < 1.5f)
		{
			player_entity_take_damage(self->player_ref, 1);
			self->player_ref->is_taking_damage = TRUE;
		}
		self->player_ref->is_taking_damage = FALSE;
		self->animation.speed = 0;
		init_astar(&self->a_star, self->player_ref->map_ref, self->super.super,
			self->player_ref->super);
	}
}
