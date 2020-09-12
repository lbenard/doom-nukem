/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:42:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "ft/str.h"
#include "maths/vec3f.h"

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
	t_monster_entity	*monster;
	t_monster_entity	*next_monster;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		if (pos->next == &self->monster_entities.list)
			break ;
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		next_monster = (t_monster_entity*)((t_entity_node*)pos->next)->entity;
		if (monster->super.perpendicular_distance
			< next_monster->super.perpendicular_distance)
		{
			list_swap_next(pos);
			pos = &self->monster_entities.list;
			continue ;
		}
	}
}

static void		iter_monster(t_raycasting_scene *const self,
	t_monster_entity *monster, float wall, const size_t mu)
{
	t_list_head			*pos;
	t_isize				cpos;

	pos = &self->monster_entities.list;
	cpos = ft_isize(self->window_ref->size.x / 2, self->window_ref->size.y / 2);
	while ((pos = pos->prev) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.is_visible
		&& is_targeting(monster, cpos, wall))
		{
			if (self->entities.weapon_ref->specs.decay == 0.0f)
				monster->health -= self->entities.weapon_ref->specs.damage * mu;
			else
				monster->health -= (self->entities.weapon_ref->specs.damage /
					(vec3f_distance(
					self->entities.player_ref->super.transform.position,
					monster->super.super.transform.position) *
					self->entities.weapon_ref->specs.decay + 1.0f)) * mu;
			monster->last_damage = get_wall_time();
			if (monster->health <= 0.0f)
				raycasting_scene_kill_monster(self, (t_entity*)monster);
			break ;
		}
	}
}

t_bool			raycasting_scene_weapon_shoot(t_raycasting_scene *const self,
					const size_t ammo_amount)
{
	t_ray				*zbuffer;
	float				wall;
	t_monster_entity	*monster;

	if (use_ammo(self->entities.weapon_ref, ammo_amount) == FALSE)
		return (FALSE);
	if (self->entities.weapon_ref->sound_ref)
		sound_play(self->entities.weapon_ref->sound_ref);
	sort(self);
	self->weapon.last_shot = get_wall_time();
	zbuffer = (t_ray*)self->zbuffer.array;
	wall = zbuffer[self->window_ref->size.x / 2].perpendicular_distance;
	monster = NULL;
	iter_monster(self, monster, wall, ammo_amount);
	self->entities.weapon_ref->just_shooted = TRUE;
	return (TRUE);
}
