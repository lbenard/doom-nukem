/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:41:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/20 19:30:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "engine/delta.h"
#include "engine/a_star.h"

void	monster_entity_update(t_monster_entity *const self)
{
	t_vec3f	position;
	t_vec2f	next_pos;
	t_vec3f	difference;
	float	distance;
	t_vec3f	direction;
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
	if (distance < 75)
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
			init_astar(&self->a_star, self->player_ref->map_ref, self->super.super, self->player_ref->super);
		}
		else
		{
			self->animation.speed = 0;
			ft_putendl("couilles");
			init_astar(&self->a_star, self->player_ref->map_ref, self->super.super, self->player_ref->super);
		}
	}
	else
		self->animation.speed = 0.0f;
}
