/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:39:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/game.h"

t_result	raycasting_scene_add_entity(t_raycasting_scene *const self,
				const t_entity_descriptor *const entity_descriptor,
				const t_vec2f pos)
{
	t_entity	*entity;

	if (!(entity = entity_list_add_entity(&self->super.entities,
		entity_descriptor->constructor_fn((t_scene*)self, pos))))
		return (ERROR);
	if (entity_descriptor == &game_singleton()->entities_list.onepunchman)
	{
		entity_list_add_entity_ref(&self->sprite_entities, entity);
		entity_list_add_entity_ref(&self->monster_entities, entity);
	}
	return (OK);
}
