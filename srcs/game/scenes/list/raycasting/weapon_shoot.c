/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/13 03:30:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "ft/str.h"
#include <math.h>

static t_bool	is_targeting(const t_monster_entity *const monster,
					const t_isize crosshair_pos,
					const float wall_distance)
{
	return (crosshair_pos.x > monster->super.start_x
		&& crosshair_pos.x < monster->super.end_x
		&& crosshair_pos.y > monster->super.start_y
		&& crosshair_pos.y < monster->super.end_y
		&& monster->super.perpendicular_distance < wall_distance);
}

static t_bool	use_ammo(t_weapon_entity *const weapon,
					const size_t ammo_amount)
{
	if (weapon->specs.clip < ammo_amount)
		return (FALSE);
	weapon->specs.clip -= ammo_amount;
	return (TRUE);
}

static void		sort(t_raycasting_scene *const self)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_list_head			*left;
	t_list_head			*right;
	t_monster_entity	*monster;
	t_monster_entity	*next_monster;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		if (pos->next == &self->monster_entities.list)
			break ;
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		next = pos->next;
		next_monster = (t_monster_entity*)((t_entity_node*)next)->entity;
		if (monster->super.perpendicular_distance
			< next_monster->super.perpendicular_distance)
		{
			left = pos->prev;
			right = next->next;
			left->next = next;
			right->prev = pos;
			pos->prev = next;
			pos->next = right;
			next->prev = left;
			next->next = pos;
			pos = &self->monster_entities.list;
			continue ;
		}
	}
}

int				distance_monster(t_raycasting_scene *const self,
					t_monster_entity *monster)
{
	t_vec3f	monster_pos;
	t_vec3f	player_pos;
	int		distance;

	monster_pos = monster->super.super.transform.position;
	player_pos = self->entities.player_ref->super.transform.position;
	distance = sqrt(pow(monster_pos.x - player_pos.x, 2) +
		pow(monster_pos.y - player_pos.y, 2));
	distance = abs(distance);
	return (distance);
}

t_bool			raycasting_scene_weapon_shoot(t_raycasting_scene *const self,
					const size_t ammo_amount)
{
	t_isize				crosshair_pos;
	t_ray				*zbuffer;
	float				wall;
	t_list_head			*pos;
	t_monster_entity	*monster;

	if (use_ammo(self->entities.weapon_ref, ammo_amount) == FALSE)
		return (FALSE);
	sort(self);
	self->weapon.last_shot = get_wall_time();
	if (self->entities.weapon_ref->sound_ref)
		sound_play(self->entities.weapon_ref->sound_ref);
	crosshair_pos.x = self->window_ref->size.x / 2;
	crosshair_pos.y = self->window_ref->size.y / 2;
	zbuffer = (t_ray*)self->zbuffer.array;
	wall = zbuffer[self->window_ref->size.x / 2].perpendicular_distance;
	pos = &self->monster_entities.list;
	while ((pos = pos->prev) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.is_visible
			&& is_targeting(monster, crosshair_pos, wall))
		{
			if (self->entities.weapon_ref->specs.decay == 0.0f)
				monster->health -= self->entities.weapon_ref->specs.damage
					* ammo_amount;
			else
				monster->health -= (self->entities.weapon_ref->specs.damage
					/ (distance_monster(self, monster)
					* self->entities.weapon_ref->specs.decay + 1.0f))
					* ammo_amount;
			if (monster->health <= 0.0f)
				raycasting_scene_kill_monster(self, (t_entity*)monster);
			break ;
		}
	}
	self->entities.weapon_ref->just_shooted = TRUE;
	return (TRUE);
}
