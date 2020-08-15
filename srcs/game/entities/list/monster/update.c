/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/14 18:24:56 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"
#include <math.h>

void	agro_if_take_damage(t_monster_entity *self)
{
	if (get_wall_time() - self->last_damage > 0.0 && get_wall_time() -
		self->last_damage <= 5.0)
		self->distance_agro = distance_monster_player(self) + 20.0;
	else
		update_agro_distance(self);
}

float	get_distance_vec(t_vec3f source, t_vec3f target)
{
	t_vec3f	difference;
	float	distance;

	difference = ft_vec3f(target.x - source.x, target.y - source.y,
		target.z - source.z);
	distance = (difference.x * difference.x + difference.y * difference.y +
		difference.z * difference.z);
	return (distance);
}

void	update_agro_distance(t_monster_entity *self)
{
	if (self->agro == TRUE)
		self->distance_agro = self->max_distance_agro;
	else
	{
		if (self->distance_agro == self->max_distance_agro)
			self->distance_agro -= 20;
	}
}

int		distance_monster_player(t_monster_entity *self)
{
	t_vec3f	position;
	t_vec3f	difference;
	t_vec3f	player_pos;
	int		distance;

	player_pos = self->super.player_ref->super.transform.position;
	position = self->super.super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
	player_pos.y - position.y,
	player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z;
	return (distance);
}

void	monster_entity_update(t_monster_entity *const self)
{
	sprite_entity_update(&self->super);
	self->animation.anim = get_orientate_sprite(self);
	animation_update(&self->animation, self->spritesheet_ref);
	frame_layer_opaque(&self->super.texture,
		animation_current(&self->animation, self->spritesheet_ref),
		ft_isize(0, 0));
	agro_if_take_damage(self);
}
