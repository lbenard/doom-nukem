/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 18:01:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include <math.h>

t_vec3f			get_straff(t_vec3f dir)
{
	t_vec3f ret;

	ret.z = 0;
	ret.x = (-1) * dir.y;
	ret.y = 1 * dir.x;
	if (((int)(ret.x * 1000) & 1) == 0)
	{
		ret.x *= -1;
		ret.y *= -1;
	}
	ret = vec3f_scalar(ret, get_last_delta() * 2);
	return (ret);
}

void			move_side(t_ghast_entity *self)
{
	t_vec3f				position;
	t_raycasting_scene	*scene;
	t_vec3f				direction;

	scene = (t_raycasting_scene*)game_singleton()->scene;
	direction = self->super.super.super.transform.direction;
	position = self->super.super.super.transform.position;
	if (self->just_shoot == FALSE)
	{
		if (self->move_side == FALSE)
		{
			self->last_pos = position;
			self->side_move = get_straff(direction);
			self->move_side = TRUE;
		}
		self->super.animation.speed = 0.1f;
		if (scene->map.map[(int)(position.x + self->side_move.x * 5) +
			((int)(position.y + self->side_move.y * 5) *
			scene->map.size.x)].id == ' ')
		{
			self->super.super.super.transform.position.x += self->side_move.x;
			self->super.super.super.transform.position.y += self->side_move.y;
			self->super.super.super.transform.position.z += self->side_move.z;
		}
	}
}

void			action_ghast(t_ghast_entity *self)
{
	t_vec3f	position;
	t_vec3f	direction;

	position = self->super.super.super.transform.position;
	direction = self->super.super.super.transform.direction;
	position = self->super.super.super.transform.position;
	direction = ft_vec3f(self->super.player_ref->super.transform.position.x -
			position.x, self->super.player_ref->super.transform.position.y -
				position.y, self->super.player_ref->super.transform.position.z -
					position.z);
	direction = vec3f_normalize(direction);
	self->super.super.super.transform.direction = direction;
	shot_fireball(self);
	move_side(self);
}

void			ghast_entity_update(t_ghast_entity *const self)
{
	sprite_entity_update(&self->super.super);
	if (self->super.animation.anim != 4)
		self->super.animation.anim = get_orientate_sprite(&self->super);
	animation_update(&self->super.animation, self->super.spritesheet_ref);
	frame_layer_opaque(&self->super.super.texture,
		animation_current(&self->super.animation, self->super.spritesheet_ref),
		ft_isize(0, 0));
	if (self->just_shoot == FALSE && self->move_side == FALSE)
		self->super.animation.speed = 0;
	if (distance_monster_player(&self->super) < self->super.distance_agro)
	{
		self->super.agro = TRUE;
		action_ghast(self);
	}
	else
	{
		self->super.agro = FALSE;
		self->super.animation.iter = 0;
		self->super.animation.speed = 0.0f;
		self->super.animation.anim = 0;
		self->last_shot_time = 0.0;
	}
	update_agro_distance(&self->super);
}
