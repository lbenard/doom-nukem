/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/28 23:15:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include <math.h>

static int		diamond_angle(float x, float y)
{
	if (y >= 0)
        return (x >= 0 ? y / (x + y) : 1 - x / (-x + y));
    else
        return (x < 0 ? 2 - y / (-x - y) : 3 + x / (x - y));
}

static int		angle_gap(float p, float m)
{
  float diff;
  
  diff = p - m;
  if (diff < 0)
  	return diff + 4;
  return diff;
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
  if (a >= 3.5 || a <= 0.5)
  	return (0);
  if (0.5 <= a && a <= 1.5)
  	return (1);
  if (1.5 <= a && a <= 2.5)
  	return (2);
  return (3);
}

static int				face_n(float a, int n)
{
	float	face;
	float	half;
	t_vec3f	range;
	int		i;

	face = 4 / n;
	half = face / 2;
	range = ft_vec2f(4 - half, half);
	if (a >= range.min || a <= range.max)
		return (0);

	i = 0;
	range = ft_vec2f(half, half + face);
	while (++i < n - 1) {
		if (range.min <= a && a <= range.max)
			return (i);
		range.min += face;
		range.max += face;
	}
	return (n - 1);
}

static int		get_orientate_sprite(t_monster_entity *self)
{
	float	angle
	int		index;

	angle = compute_angle_to_player(self);
	index = face_n(angle, self->spritesheet_ref->grid_size.y);
	return (index);
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
