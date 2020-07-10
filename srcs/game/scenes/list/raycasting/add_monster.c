/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_monster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:14:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 18:24:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_result	raycasting_scene_add_monster(t_raycasting_scene *const self,
				t_constructor constructor)
{
	t_monster_entity	*new_monster;

	if (!(new_monster = (t_monster_entity*)entity_list_add_entity(
		&self->super.entities,
		constructor)))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->sprite_entities,
		(t_entity*)new_monster))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->monster_entities,
		(t_entity*)new_monster))
		return (ERROR);
	return (OK);
}
