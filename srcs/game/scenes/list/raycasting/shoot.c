/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:46:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 02:43:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

#include <stdio.h>

void	raycasting_scene_shoot(t_raycasting_scene *const self)
{
	t_list_head			*pos;
	t_monster_entity	*monster;
	t_isize				crosshair_pos;
	double				time;
	float				wall;

	time = get_wall_time();
	if (self->weapon.last_shot + self->weapon.shoot_time > time)
		return ;
	self->weapon.last_shot = time;
	crosshair_pos.x = self->window_ref->size.x / 2;
	crosshair_pos.y = self->window_ref->size.y / 2;
	pos = &self->monster_entities.list;
	sound_play(&self->pistol);
	wall = ((t_ray*)self->zbuffer.array)
		[self->window_ref->size.x / 2].perpendicular_distance;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (crosshair_pos.x > monster->super.last_start_x
			&& crosshair_pos.x < monster->super.last_end_x
			&& crosshair_pos.y > monster->super.last_start_y
			&& crosshair_pos.y < monster->super.last_end_y
			&& monster->super.last_perpendicular_distance < wall)
		{
			monster->health -= self->weapon.damage;
			if (monster->health <= 0.0f)
			{
				entity_list_remove(&self->monster_entities, (t_entity*)monster);
				entity_list_remove(&self->sprite_entities, (t_entity*)monster);
				entity_list_remove(&self->super.entities, (t_entity*)monster);
			}
			break ;
		}
	}
}
