/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/07 23:06:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include <math.h>

// static float	angle_gap(float f1, float f2)
// {
// 	float	result;
	
// 	f1 += PI;
// 	f2 += PI;
// 	result =  ((f1 > f2) ? f1 - f2 : -(f2 - f1));
// 	if (result > PI)
// 		result = -(2 * PI - result);
// 	if (result < -PI)
// 		result = (result + 2 * PI);
// 	return (result);
// }

// static float	compute_angle_to_player(t_ghast_entity *self)
// {
// 	t_vec3f	player_pos;
// 	t_vec3f	monster_pos;
// 	t_vec3f	dir_to_player;
// 	float	monster_angle;
// 	float	player_angle;

// 	player_pos = self->super.player_ref->super.transform.position;
// 	monster_pos = self->super.super.super.transform.position;
// 	dir_to_player = ft_vec3f(player_pos.x - monster_pos.x,
// 						player_pos.y - monster_pos.y, 0);
// 	monster_angle = atan2f(self->super.super.super.transform.direction.x,
// 		self->super.super.super.transform.direction.y);
// 	player_angle = atan2f(dir_to_player.x, dir_to_player.y);
// 	return (angle_gap(monster_angle, player_angle));
// }

// static int		get_orientate_sprite(t_ghast_entity *self)
// {
// 	float	angle;
// 	float	angle_abs;

// 	angle = compute_angle_to_player(self);
// 	angle_abs = fabsf(angle);
// 	if (angle_abs <= PI / 8.0f)
// 		return (0);
// 	else if (angle_abs >= PI * (7.0f / 8.0f))
// 		return (4);
// 	else if (angle_abs <= PI * (3.0f / 8.0f))
// 		return ((angle > 0) ? 7 : 1);
// 	else if (angle_abs <= PI * (5.0f / 8.0f))
// 		return ((angle > 0) ? 6 : 2);
// 	else
// 		return ((angle > 0) ? 5 : 3);
// }

void			go_fireball(t_ghast_entity *self)
{
	t_vec3f				monster_pos;
	t_vec3f				direction;
	t_raycasting_scene	*scene;

	monster_pos = self->super.super.super.transform.position;
	scene = (t_raycasting_scene*)game_singleton()->scene;
	direction.x = self->super.player_ref->super.transform.position.x -
		monster_pos.x;
	direction.y = self->super.player_ref->super.transform.position.y -
		monster_pos.y;
	direction.z = self->super.player_ref->super.transform.position.z -
		monster_pos.z;
	direction = vec3f_normalize(direction);
	entity_list_add_entity(&scene->super.entities,
		fireball_entity(monster_pos, direction, self->super.player_ref));
}

void			ghast_entity_update(t_ghast_entity *const self)
{
	t_vec3f	position;
	t_vec2f	next_pos;
	t_vec3f	difference;
	t_vec3f	direction;
	float	distance;
	t_vec3f	player_pos;

	sprite_entity_update(&self->super.super);
	animation_update(&self->super.animation, self->super.spritesheet_ref);
	if (self->just_shoot == FALSE)
		self->super.animation.speed = 0;
	frame_layer_opaque(&self->super.super.texture,
		animation_current(&self->super.animation, self->super.spritesheet_ref),
		ft_isize(0, 0));
	player_pos = self->super.super.player_ref->super.transform.position;
	position = self->super.super.super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
    player_pos.y - position.y,
    player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z; 
	if (distance < 50)
	{
		// ft_putendl("ya un pb ?");
		self->super.animation.speed = 0.4;
		self->super.animation.speed = 0.1f;
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
		// self->super.super.super.transform.position.x += direction.x;
		// self->super.super.super.transform.position.y += direction.y;
		// self->super.super.super.transform.position.z += direction.z;
		self->super.super.super.transform.direction = direction;
		// self->super.animation.anim = get_orientate_sprite(self) / 2;
		// animation_update(&self->animation, self->spritesheet_ref);
		// init_astar(&self->super.a_star,
		// 	self->super.player_ref->map_ref,
		// 	self->super.super.super,
		// 	self->super.player_ref->super);
		if (self->last_shot_time == 0.0)
			self->last_shot_time = get_wall_time();
		if (self->last_shot_time + self->shoot_time < get_wall_time())
		{
			self->just_shoot = TRUE;
			self->super.animation.iter = 0;
			self->super.animation.anim = 4;
			self->super.animation.speed = 0.1f;
			go_fireball(self);
			self->last_shot_time = get_wall_time();
		}
		// printf("anim = %d, index = %f, iter = %d\n", self->super.animation.anim, self->super.spritesheet_ref->grid_size.x * (1 / 0.1) - 1, self->super.animation.iter);
		if (self->super.animation.anim == 4 && self->super.animation.iter ==
			(int)(self->super.spritesheet_ref->grid_size.x * (1 / 0.1) - 1))
		{
			// printf("fin de l'animation ?\n");
			self->super.animation.speed = 0;
			self->super.animation.anim = 0;
			self->just_shoot = FALSE;
		}
		// if (self->super.is_star == FALSE)
		// {
		// 	init_astar(&self->super.a_star, self->super.super.player_ref->map_ref,
		// 		self->super.super.super, self->super.super.player_ref->super);
		// 	self->super.is_star = TRUE;
		// }
		// if (((ssize_t)self->super.super.super.transform.position.x != self->super.a_star.next_pos.pos.x) || 
		// 		((ssize_t)self->super.super.super.transform.position.y != self->super.a_star.next_pos.pos.y))
		// {
		// else
		// {
		// 	if (self->super.player_ref->is_taking_damage == FALSE && distance < 1.5f)
		// 	{
		// 		player_entity_take_damage(self->super.player_ref, self->super.damage);
		// 		self->super.player_ref->is_taking_damage = TRUE;
		// 	}
		// 	self->super.player_ref->is_taking_damage = FALSE;
		// 	self->super.animation.speed = 0;
		// 	init_astar(&self->super.a_star,
		// 		self->super.player_ref->map_ref,
		// 		self->super.super.super,
		// 		self->super.player_ref->super);
		// }
	}
	else
	{
		// self->super.animation.anim = get_orientate_sprite(self);
		self->super.animation.iter = 0;
		self->super.animation.speed = 0;
		self->super.animation.anim = 0;
		self->last_shot_time = 0.0;
		self->super.animation.speed = 0.0f;
	}
}
