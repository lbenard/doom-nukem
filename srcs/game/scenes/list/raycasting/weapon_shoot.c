/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/29 16:20:41 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_bool	use_ammo(t_weapon *const weapon, const size_t ammo_amount)
{
    if (weapon->clip < ammo_amount)
        return (FALSE);
    weapon->clip -= ammo_amount;
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
			list_move(pos, pos->prev);
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
	player_pos = self->player_ref->super.transform.position;
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

	if (!use_ammo(&self->weapon.weapon, ammo_amount))
		return (FALSE);
	sort(self);
	sound_play(&self->pistol);
	crosshair_pos.x = self->window_ref->size.x / 2;
	crosshair_pos.y = self->window_ref->size.y / 2;
	zbuffer = (t_ray*)self->zbuffer.array;
	wall = zbuffer[self->window_ref->size.x / 2].perpendicular_distance;
	pos = &self->monster_entities.list;
	while ((pos = pos->prev) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (is_targeting(monster, crosshair_pos, wall))
		{
			if (ft_strcmp(self->weapon.weapon.name, "Shotgun") == 0)
			{

				monster->health -= (self->weapon.weapon.damage / (distance_monster(self, monster))) * ammo_amount;
			}
			else
				monster->health -= self->weapon.weapon.damage * ammo_amount;
			if (monster->health <= 0.0f)
				raycasting_scene_kill_monster(self, (t_entity*)monster);
			break ;
		}
	}
	self->weapon.just_shooted = TRUE;
	return (TRUE);
}
