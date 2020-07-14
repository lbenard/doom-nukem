/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/13 22:36:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static t_bool	is_targeting(const t_monster_entity *const monster,
					const t_isize crosshair_pos,
					const float wall_distance)
{
	return (crosshair_pos.x > monster->super.last_start_x
		&& crosshair_pos.x < monster->super.last_end_x
		&& crosshair_pos.y > monster->super.last_start_y
		&& crosshair_pos.y < monster->super.last_end_y
		&& monster->super.last_perpendicular_distance < wall_distance);
}

static t_bool	use_ammo(t_weapon *const weapon, const size_t ammo_amount)
{
    if (weapon->clip < ammo_amount)
        return (FALSE);
    weapon->clip -= ammo_amount;
    return (TRUE);
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
	sound_play(&self->pistol);
	crosshair_pos.x = self->window_ref->size.x / 2;
	crosshair_pos.y = self->window_ref->size.y / 2;
	zbuffer = (t_ray*)self->zbuffer.array;
	wall = zbuffer[self->window_ref->size.x / 2].perpendicular_distance;
	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (is_targeting(monster, crosshair_pos, wall))
		{
			monster->health -= self->weapon.weapon.damage * ammo_amount;
			if (monster->health <= 0.0f)
				raycasting_scene_kill_monster(self, (t_entity*)monster);
			break ;
		}
	}
	self->weapon.just_shooted = TRUE;
	return (TRUE);
}
