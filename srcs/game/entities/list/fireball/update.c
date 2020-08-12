/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:47:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 14:41:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"
#include "engine/delta.h"

void			fireball_entity_update(t_fireball_entity *const self)
{
	t_vec3f				direction;
	t_vec3f				player_pos;
	float				distance;
	t_raycasting_scene	*scene;

	sprite_entity_update(&self->super);
	scene = (t_raycasting_scene*)game_singleton()->scene;
	direction = self->super.super.transform.direction;
	player_pos = self->super.player_ref->super.transform.position;
	distance = get_distance_vec(self->super.super.transform.position,
		player_pos);
	direction = vec3f_scalar(direction, get_last_delta() * 6);
	self->super.super.transform.position = vec3f_addition(
		self->super.super.transform.position, direction);
	if (distance <= 0.35f)
	{
		player_entity_take_damage(scene->entities.player_ref, self->damage);
		entity_list_remove(&scene->super.entities, &self->super.super);
		return ;
	}
	if (self->super.super.transform.position.x < 0.0f
		|| self->super.super.transform.position.y < 0.0f
		|| self->super.super.transform.position.x >= self->map_ref->size.x
		|| self->super.super.transform.position.y >= self->map_ref->size.y
		|| self->map_ref->map[(int)self->super.super.transform.position.y
			* self->map_ref->size.x
			+ (int)self->super.super.transform.position.x].id != ' ')
	{
		entity_list_remove(&scene->super.entities, &self->super.super);
		return ;
	}
}
