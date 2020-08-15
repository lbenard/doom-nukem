/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:47:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/16 00:23:32 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"
#include "engine/delta.h"

#include <stdio.h>

int		check_fireball_position(t_fireball_entity *self,
	t_raycasting_scene *scene)
{
	printf("dans check\n");
	if (self->super.super.transform.position.x < 0.0f
		|| self->super.super.transform.position.y < 0.0f
		|| self->super.super.transform.position.x >= self->map_ref->size.x
		|| self->super.super.transform.position.y >= self->map_ref->size.y
		|| self->map_ref->map[(int)self->super.super.transform.position.y
			* self->map_ref->size.x
			+ (int)self->super.super.transform.position.x].id != ' ')
	{
		ft_putendl("c'est bon");
		entity_list_remove(&scene->super.entities, &self->super.super);
		return (0);
	}
	else
		return (1);
}

void	fireball_entity_update(t_fireball_entity *const self)
{
	t_vec3f				direction;
	t_vec3f				player_pos;
	float				distance;
	t_raycasting_scene	*scene;

	printf("debut update\n");
	sprite_entity_update(&self->super);
	animation_update(&self->anim, self->spritesheet_ref);
	frame_layer_opaque(&self->super.texture,
		animation_current(&self->anim, self->spritesheet_ref),
		ft_isize(0, 0));
	printf("apres layer update\n");
	if (self->anim.iter >= self->spritesheet_ref->grid_size.x *
			(1 / self->anim.speed) - 1)
	{
		if (self->anim.anim > 3)
			self->anim.anim = 0;
		else
			self->anim.anim++;
	}
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
	if (check_fireball_position(self, scene) == 0)
		return ;
}
