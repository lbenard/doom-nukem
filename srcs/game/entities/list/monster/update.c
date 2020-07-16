/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 03:29:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "engine/delta.h"

void	monster_entity_update(t_monster_entity *const self)
{
	t_vec3f	position;
	t_vec3f	player_pos;
	t_vec3f	difference;
	float	distance;
	t_vec3f	direction;

	animation_update(&self->animation, self->spritesheet_ref);
	frame_layer_opaque(&self->super.texture,
		animation_current(&self->animation, self->spritesheet_ref),
		ft_isize(0, 0));
	position = self->super.super.transform.position;
	player_pos = self->player_ref->super.transform.position;
	difference = ft_vec3f(player_pos.x - position.x,
		player_pos.y - position.y,
		player_pos.z - position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
		+ difference.z * difference.z;
	if (distance < 75)
	{
		self->animation.speed = 1.0f;
		direction = difference;
		direction = vec3f_normalize(direction);
		direction = vec3f_scalar(direction, 2.0f);
		direction = vec3f_scalar(direction, get_last_delta());
		self->super.super.transform.position.x += direction.x;
		self->super.super.transform.position.y += direction.y;
		self->super.super.transform.position.z += direction.z;
	}
	else
		self->animation.speed = 0.0f;
}
