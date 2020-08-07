/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:43:57 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/07 14:23:02 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include "game/entities/fireball_entity.h"
#include "game/entities/monster_entity.h"
#include <math.h>

// void	rotate_vector(t_nyarlathotep_entity *self)
// {

// }

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

int                index_side(int back_to_front_index, int back_index, int sign)
{
    return (back_index + sign * back_to_front_index);
}

static int        get_spritesheet_index(float angle, int n)
{
    float    angle_abs;
    int        check_amount;
    t_vec2i    range;
    int        i;

    check_amount = (n - 2) / 2;
    angle_abs = fabsf(angle);
    range = ft_vec2i(0, 1);

    if (range.x * (PI / n) <= angle_abs && angle_abs <= range.y * (PI / n))
        return (n / 2);
    i = -1;
    while (++i < check_amount)
    {
        range = ft_vec2i(range.y, range.y + 2);
        if (range.x * (PI / n) <= angle_abs && angle_abs <= range.y * (PI / n))
            return (index_side(i, n / 2, (angle < 0 ? -1 : 1)));
    }
    return (0);
}

// static int		get_orientate_sprite(t_monster_entity *self)
// {
// 	float	angle;
// 	float	angle_abs;

// 	angle = compute_angle_to_player(self);
// 	angle_abs = fabsf(angle);
// 	// if (angle_abs <= PI / 8.0f)
// 	// 	return (0);
// 	// else if (angle_abs >= PI * (7.0f / 8.0f))
// 	// 	return (4);
// 	// else if (angle_abs <= PI * (3.0f / 8.0f))
// 	// 	return ((angle > 0) ? 7 : 1);
// 	// else if (angle_abs <= PI * (5.0f / 8.0f))
// 	// 	return ((angle > 0) ? 6 : 2);
// 	// else
// 	// 	return ((angle > 0) ? 5 : 3);
// 	if (angle_abs <= PI / 8.0f)
// 		return (0);
// 	else if (angle_abs >= PI * (7.0f / 8.0f))
// 		return (2);
// 	else if (angle_abs <= PI * (3.0f / 8.0f))
// 		return ((angle > 0) ? 3 : 0);
// 	else if (angle_abs <= PI * (5.0f / 8.0f))
// 		return ((angle > 0) ? 3 : 1);
// 	else
// 		return ((angle > 0) ? 3 : 2);
// }

static int		get_orientate_sprite(t_monster_entity *self)
{
	float	angle;
	int		orientations;

	angle = compute_angle_to_player(self);
	orientations = self->spritesheet_ref->grid_size.y;
	return (get_spritesheet_index(angle, orientations));
}

void	nyarlathotep_entity_update(t_nyarlathotep_entity *const self)
{
	t_vec3f	position;
	t_vec3f	player_pos;
	t_vec3f	difference;
	float	distance;
	t_vec3f	velocity;

	sprite_entity_update(&self->super.super);
	animation_update(&self->super.animation, self->super.spritesheet_ref);
	self->super.animation.anim = get_orientate_sprite(&self->super);
	printf("anim = %d\n", self->super.animation.anim);
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
	velocity = vec3f_scalar(velocity, get_last_delta() * 2);
	// self->super.super.super.transform.position.x += velocity.x;
	// self->super.super.super.transform.position.y += velocity.y;
	// self->super.super.super.transform.position.z += velocity.z;
}
