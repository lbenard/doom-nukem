// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   update.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/08/07 01:43:57 by mribouch          #+#    #+#             */
// /*   Updated: 2020/08/08 14:44:51 by mribouch         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "game/entities/nyarlathotep_entity.h"
// #include "engine/delta.h"
// #include "engine/a_star.h"
// #include "game/entities/fireball_entity.h"
// #include "game/entities/monster_entity.h"
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>


#include "game/entities/nyarlathotep_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include "game/entities/monster_entity.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void	a_star_attack(t_monster_entity *self, int distance, float speed)
{
	t_vec3f	position;
	t_vec2f	next_pos;
	t_vec3f	difference;
	t_vec3f	direction;

	if (self->is_star == FALSE)
	{
		init_astar(&self->a_star, self->player_ref->map_ref,
			self->super.super, self->player_ref->super);
		self->is_star = TRUE;
	}
	if (((ssize_t)self->super.super.transform.position.x != self->a_star.next_pos.pos.x) || 
			((ssize_t)self->super.super.transform.position.y != self->a_star.next_pos.pos.y))
	{
		// self->animation.speed = 1.0f;
		position = self->super.super.transform.position;
		next_pos.x = self->a_star.next_pos.pos.x;
		next_pos.y = self->a_star.next_pos.pos.y;
		next_pos.x += 0.5f;
		next_pos.y += 0.5f;
		difference = ft_vec3f((float)next_pos.x - position.x,
			(float)next_pos.y - position.y,
	 		0.0f);
		direction = difference;
		direction = vec3f_normalize(direction);
		direction = vec3f_scalar(direction, 2.0f);
		direction = vec3f_scalar(direction, get_last_delta() * speed);
		self->super.super.transform.position.x += direction.x;
		self->super.super.transform.position.y += direction.y;
		self->super.super.transform.position.z += direction.z;
		self->super.super.transform.direction = vec3f_normalize(direction);
		// animation_update(&self->animation, self->spritesheet_ref);
		init_astar(&self->a_star, self->player_ref->map_ref, self->super.super, self->player_ref->super);
	}
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
		init_astar(&self->a_star, self->player_ref->map_ref, self->super.super, self->player_ref->super);
	}
}

int		get_distance_vec(t_vec3f source, t_vec3f target)
{
	t_vec3f	difference;
	int		distance;

	difference = ft_vec3f(target.x - source.x, target.y - source.y,
		target.z - source.z);
	distance = (difference.x * difference.x + difference.y * difference.y +
		difference.z * difference.z);
	return (distance);
}

t_vec3f	get_dir_move(t_nyarlathotep_entity *self, t_map map)
{
	t_vec3f	verif;
	t_vec3f	ret;
	t_vec3f	position;
	int		na;
	
	na = 0;
	position = self->super.super.super.transform.position;
	ret = ft_vec3f(0, 0, 0);
	na = ((int)(get_wall_time() - (int)get_wall_time()) * 100000) % 7; // initialisation de rand
	na = (rand() % (7 - 1 + 1)) + 1;
	printf("na = %d\n", na);
	if (na == 1)
		ret = ft_vec3f(1, 0, 0);
	else if (na == 2)
		ret = ft_vec3f(1, 1, 0);
	else if (na == 3)
		ret = ft_vec3f(0, 1, 0);
	else if (na == 4)
		ret = ft_vec3f(0, -1, 0);
	else if (na == 5)
		ret = ft_vec3f(-1, 0, 0);
	else if (na == 6)
		ret = ft_vec3f(-1, 1, 0);
	else if (na == 7)
		ret = ft_vec3f(-1, -1, 0);
	verif = vec3f_normalize(ret);
	verif = vec3f_scalar(ret, 2.0f);
	verif = vec3f_scalar(ret, get_last_delta() * 2);
	if (map.map[(int)(position.x + verif.x * 6) +
			((int)(position.y + verif.y * 6) *
			map.size.x)].id == ' ')
	{
		ret.x *= -1;
		ret.y *= -1;
		ret.z *= -1;
	}
	printf("ret.x = %f, ret.y = %f\n", ret.x, ret.y);
	return (ret);
}

void	nyarlathotep_entity_update(t_nyarlathotep_entity *const self)
{
	t_vec3f	position;
	t_vec3f	player_pos;
	t_vec3f	difference;
	float	distance;
	t_vec3f	velocity;
	static int	angle;
	t_raycasting_scene	*scene;

	sprite_entity_update(&self->super.super);
	self->super.animation.anim = get_orientate_sprite(&self->super);
	animation_update(&self->super.animation, self->super.spritesheet_ref);
	// self->super.animation.anim = get_orientate_sprite(&self->super);
	// printf("anim = %d\n", self->super.animation.anim);
	frame_layer_opaque(&self->super.super.texture,
		animation_current(&self->super.animation, self->super.spritesheet_ref),
		ft_isize(0, 0));
	scene = (t_raycasting_scene*)game_singleton()->scene;
	velocity = ft_vec3f(0, 0, 0);
	position = self->super.super.super.transform.position;
	player_pos = self->super.player_ref->super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
		player_pos.y - position.y,
		player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z;
	if (distance < self->super.distance_agro)
	{
		self->super.agro = TRUE;
		self->super.animation.speed = 0.4f;
		self->is_moving = TRUE;
		a_star_attack(&self->super, distance, 2.5);
		// velocity.x += difference.x;
		// velocity.y += difference.y;
		// velocity.z += difference.z;
	}
	else
	{
		self->super.agro = FALSE;
		if (angle >= 360)
		{
			self->end_circle = TRUE;
			self->end_move = FALSE;
			angle = 0;
		}
		velocity = ft_vec3f(cos(angle * (PI / 180)), sin(angle * (PI / 180)), 0.0f);
		if (self->is_moving == FALSE)
			self->super.super.super.transform.direction = velocity;
		self->super.animation.speed = 0.0f;
		angle++;
		if (self->end_circle == TRUE && self->end_move == FALSE && self->is_moving == FALSE)
		{
			self->last_pos = self->super.super.super.transform.position;
			self->dir_move = get_dir_move(self, scene->map);
			self->is_moving = TRUE;
		}
		if(self->is_moving == TRUE)
		{
			velocity = self->dir_move;
			if (get_distance_vec(self->last_pos, self->super.super.super.transform.position) > 3)
			{
				self->is_moving = FALSE;
				self->end_move = TRUE;
			}
		}
		velocity = vec3f_normalize(velocity);
		velocity = vec3f_scalar(velocity, 2.0f);
		velocity = vec3f_scalar(velocity, get_last_delta() * 2);
		if (scene->map.map[(int)(position.x + velocity.x * 6) +
				((int)(position.y + velocity.y * 6) *
				scene->map.size.x)].id == ' ')
		{
			if (self->is_moving == TRUE)
			{
				self->super.super.super.transform.direction = velocity;
				self->super.super.super.transform.position.x += velocity.x;
				self->super.super.super.transform.position.y += velocity.y;
				self->super.super.super.transform.position.z += velocity.z;
			}
		}
		else
			self->is_moving = FALSE;
		if (self->is_moving == TRUE)
			self->super.animation.speed = 0.4f;
		else
			self->super.animation.speed = 0.0f;
		angle++;
	}
	if (self->super.agro == TRUE)
		self->super.distance_agro = self->super.max_distance_agro;
	else
	{
		if (self->super.distance_agro == self->super.max_distance_agro)
			self->super.distance_agro -= 20;
	}
	// printf("cos = %f, sin = %f\n", cos(angle * (PI / 180)), sin(angle * (PI / 180)));
	// printf("angle = %d", angle);
	// printf("time = %f", get_wall_time());
}
