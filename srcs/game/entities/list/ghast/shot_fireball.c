/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot_fireball.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 23:38:52 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/06 23:50:15 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"
#include "game/entities/ghast_entity.h"
#include "engine/delta.h"

static void	go_fireball(t_ghast_entity *self)
{
	t_vec3f				monster_pos;
	t_vec3f				direction;
	t_raycasting_scene	*scene;

	monster_pos = self->super.super.super.transform.position;
	scene = (t_raycasting_scene*)game_singleton()->scene;
	direction = ft_vec3f(self->super.player_ref->super.transform.position.x -
		monster_pos.x, self->super.player_ref->super.transform.position.y -
			monster_pos.y, self->super.player_ref->super.transform.position.z -
				monster_pos.z);
	direction = vec3f_normalize(direction);
	entity_list_add_entity(&scene->super.entities,
		fireball_entity(monster_pos, direction, self->super.player_ref));
}

void		shot_fireball(t_ghast_entity *self)
{
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
		self->move_side = FALSE;
	}
	if (self->super.animation.anim == 4 && self->super.animation.iter ==
		(int)(self->super.spritesheet_ref->grid_size.x * (1 / 0.1) - 1))
	{
		self->super.animation.speed = 0;
		self->super.animation.anim = 0;
		self->just_shoot = FALSE;
	}
}
