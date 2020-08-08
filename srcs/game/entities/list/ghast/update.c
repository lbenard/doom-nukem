/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/08 18:22:17 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include <math.h>

static float		diamond_angle(float x, float y)
{
	if (y >= 0)
        return (x >= 0 ? y / (x + y) : 1 - x / (-x + y));
    else
        return (x < 0 ? 2 - y / (-x - y) : 3 + x / (x - y));
}

static float		angle_gap(float p, float m)
{
  float diff;
  
  diff = p - m;
  if (diff < 0)
  	return diff + 4;
  return (diff);
}

static float	compute_angle_to_player(t_monster_entity *self)
{
	t_vec3f	player_pos;
	t_vec3f	monster_pos;
	t_vec3f	dir_to_player;
	float	monster_angle;
	float	player_angle;

	player_pos = self->player_ref->super.transform.position;
	monster_pos = self->super.super.transform.position;
	dir_to_player = ft_vec3f(player_pos.x - monster_pos.x,
						player_pos.y - monster_pos.y, 0);
	monster_angle = diamond_angle(self->super.super.transform.direction.x,
		self->super.super.transform.direction.y);
	player_angle = diamond_angle(dir_to_player.x, dir_to_player.y);
	return (angle_gap(player_angle, monster_angle));
}

static int				face4(float a)
{
	// printf("angle = %f\n", a);
  if (a >= 3.5 || a <= 0.5)
  	return (0);
  if (0.5 <= a && a <= 1.5)
  	return (3);
  if (1.5 <= a && a <= 2.5)
  	return (2);
  return (1);
}

static int		get_orientate_sprite(t_monster_entity *self)
{
	float	angle;
	int		index;

	angle = compute_angle_to_player(self);
	index = face4(angle);
	// printf("index = %d\n", index);
	return (index);
}

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
	ret = vec3f_scalar(ret, get_last_delta());
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

int				get_distance(t_ghast_entity *self)
{
	t_vec3f	position;
	t_vec3f	difference;
	t_vec3f	player_pos;
	int		distance;

	player_pos = self->super.super.player_ref->super.transform.position;
	position = self->super.super.super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
	player_pos.y - position.y,
	player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z;
	return (distance);
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
	t_vec3f	position;
	t_vec3f	player_pos;

	sprite_entity_update(&self->super.super);
	if (self->super.animation.anim != 4)
		self->super.animation.anim = get_orientate_sprite(&self->super);
	// printf("anim = %d\n", self->super.animation.anim);
	animation_update(&self->super.animation, self->super.spritesheet_ref);
	if (self->just_shoot == FALSE && self->move_side == FALSE)
		self->super.animation.speed = 0;
	// self->super.animation.anim = get_orientate_sprite(&self->super);
	frame_layer_opaque(&self->super.super.texture,
		animation_current(&self->super.animation, self->super.spritesheet_ref),
		ft_isize(0, 0));
	player_pos = self->super.super.player_ref->super.transform.position;
	position = self->super.super.super.transform.position;
	if (get_distance(self) < self->super.distance_agro)
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
	if (self->super.agro == TRUE)
		self->super.distance_agro = self->super.max_distance_agro;
	else
	{
		if (self->super.distance_agro == self->super.max_distance_agro)
			self->super.distance_agro -= 20;
	}
}
