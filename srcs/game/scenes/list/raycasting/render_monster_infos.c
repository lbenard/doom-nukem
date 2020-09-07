/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 22:13:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/06 02:09:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "maths/maths.h"
#include "engine/delta.h"

void			raycasting_scene_render_monster_infos(
					t_raycasting_scene *const self,
					t_frame *const fb)
{
	t_list_head			*pos;
	t_monster_entity	*monster;
	t_u8				distance_opacity;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		if (monster->super.perpendicular_distance > 10.0f
			|| !monster->super.is_visible)
			continue ;
		distance_opacity = inverse_lerp(10.0f, 0.0f,
			monster->super.perpendicular_distance) * 255;
		monster_entity_render_name(monster, fb, distance_opacity);
		if (monster->health < monster->full_health)
			monster_entity_render_health(monster, fb, distance_opacity);
	}
}
