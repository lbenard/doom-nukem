/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/06 21:16:53 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include <math.h>

static float	angle_gap(float f1, float f2)
{
	float	result;
	
	f1 += PI;
	f2 += PI;
	result =  ((f1 > f2) ? f1 - f2 : -(f2 - f1));
	if (result > PI)
		result = -(2 * PI - result);
	if (result < -PI)
		result = (result + 2 * PI);
	return (result);
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
	monster_angle = atan2f(self->super.super.transform.direction.x,
		self->super.super.transform.direction.y);
	player_angle = atan2f(dir_to_player.x, dir_to_player.y);
	return (angle_gap(monster_angle, player_angle));
}

static int		get_orientate_sprite(t_monster_entity *self)
{
	float	angle;
	float	angle_abs;

	angle = compute_angle_to_player(self);
	angle_abs = fabsf(angle);
	if (angle_abs <= PI / 8.0f)
		return (0);
	else if (angle_abs >= PI * (7.0f / 8.0f))
		return (4);
	else if (angle_abs <= PI * (3.0f / 8.0f))
		return ((angle > 0) ? 7 : 1);
	else if (angle_abs <= PI * (5.0f / 8.0f))
		return ((angle > 0) ? 6 : 2);
	else
		return ((angle > 0) ? 5 : 3);
}

void			monster_entity_update(t_monster_entity *const self)
{
	t_vec3f	position;
	t_vec2f	next_pos;
	t_vec3f	difference;
	t_vec3f	direction;
	float	distance;
	t_vec3f	player_pos;

	sprite_entity_update(&self->super);
	animation_update(&self->animation, self->spritesheet_ref);
	frame_layer_opaque(&self->super.texture,
		animation_current(&self->animation, self->spritesheet_ref),
		ft_isize(0, 0));
	player_pos = self->player_ref->super.transform.position;
	position = self->super.super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
    player_pos.y - position.y,
    player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z; 
	if (distance < 30)
	{
		if (self->is_star == FALSE)
		{
			init_astar(&self->a_star, self->player_ref->map_ref,
				self->super.super, self->player_ref->super);
			self->is_star = TRUE;
		}
		if (((ssize_t)self->super.super.transform.position.x != self->a_star.next_pos.pos.x) || 
				((ssize_t)self->super.super.transform.position.y != self->a_star.next_pos.pos.y))
		{
			self->animation.speed = 1.0f;
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
			direction = vec3f_scalar(direction, get_last_delta());
			self->super.super.transform.position.x += direction.x;
			self->super.super.transform.position.y += direction.y;
			self->super.super.transform.position.z += direction.z;
			self->super.super.transform.direction = vec3f_normalize(direction);
			self->animation.anim = get_orientate_sprite(self);
			// animation_update(&self->animation, self->spritesheet_ref);
			init_astar(&self->a_star, self->player_ref->map_ref, self->super.super, self->player_ref->super);
		}
		else
		{
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
	else
	{
		self->animation.anim = get_orientate_sprite(self);
		self->animation.speed = 0.0f;
	}
}
