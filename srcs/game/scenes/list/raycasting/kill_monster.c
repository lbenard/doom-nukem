/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/13 19:58:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_kill_monster(t_raycasting_scene *const self,
			const t_entity *const monster)
{
	entity_list_remove(&self->monster_entities, monster);
	entity_list_remove(&self->sprite_entities, monster);
	entity_list_remove(&self->super.entities, monster);
}
