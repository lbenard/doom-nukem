/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:43:57 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/20 18:39:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include "game/entities/monster_entity.h"
#include <math.h>

void	move_dir(t_nyarlathotep_entity *self,
			t_vec3f velocity,
			t_raycasting_scene *scene)
{
	t_vec3f position;

	position = self->super.super.super.transform.position;
	if (scene->map.map[(int)(position.x + velocity.x * 6) +
			((int)(position.y + velocity.y * 6) *
			scene->map.size.x)].id == ' ')
	{
		if (self->is_moving == TRUE)
		{
			self->super.super.super.transform.direction = velocity;
			self->super.super.super.transform.position = vec3f_addition(
				self->super.super.super.transform.position, velocity);
		}
	}
	else
		self->is_moving = FALSE;
}

void	move_nyarlathotep(t_nyarlathotep_entity *self,
			t_vec3f velocity,
			t_raycasting_scene *scene)
{
	if (self->is_moving == TRUE)
	{
		velocity = self->dir_move;
		if (get_distance_vec(self->last_pos,
			self->super.super.super.transform.position) > 3)
		{
			self->is_moving = FALSE;
			self->end_move = TRUE;
		}
	}
	velocity = vec3f_normalize(velocity);
	velocity = vec3f_scalar(velocity, get_last_delta() * 4);
	move_dir(self, velocity, scene);
}

void	update_moving_anim(t_nyarlathotep_entity *self)
{
	if (self->is_moving == TRUE)
		self->super.animation.speed = 0.4f;
	else
		self->super.animation.speed = 0.0f;
}

void	nyarlathotep_entity_update(t_nyarlathotep_entity *const self)
{
	float				distance;
	t_vec3f				velocity;
	t_raycasting_scene	*scene;

	monster_entity_update(&self->super);
	scene = (t_raycasting_scene*)game_singleton()->scene;
	if ((distance = distance_monster_player(&self->super)) <
		self->super.distance_agro)
	{
		self->super.agro = TRUE;
		self->super.animation.speed = 0.4f;
		self->is_moving = TRUE;
		a_star_attack(&self->super, distance, 4.5);
	}
	else
	{
		self->super.agro = FALSE;
		velocity = ft_vec3f(cos(self->angle * (PI / 180)),
			sin(self->angle * (PI / 180)), 0.0f);
		rotate_nyarlathotep(self, scene, velocity);
		move_nyarlathotep(self, velocity, scene);
		update_moving_anim(self);
		self->angle++;
	}
	update_agro_distance(&self->super);
}
