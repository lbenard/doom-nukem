/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:22:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 22:32:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_add_entities(t_raycasting_scene *const self)
{
	t_list_head			*pos;
	t_map_entity_node	*node;
	t_entity_descriptor	*descriptor;

	if (!self->super.module.has_error)
		self->entities.player_ref = (t_player_entity*)entity_list_add_entity(
			&self->super.entities, player_entity(&self->map, self->fov));
	if (!self->super.entities.module.has_error)
	{
		pos = &self->map.entities;
		while ((pos = pos->next) != &self->map.entities)
		{
			node = (t_map_entity_node*)((t_u8*)pos
				- __builtin_offsetof(t_map_entity_node, node));
			descriptor = entity_descriptor_from_name(
				(t_entity_descriptor*)&game_singleton()->entities_list,
				sizeof(game_singleton()->entities_list)
					/ sizeof(t_entity_descriptor), node->name);
			if (!descriptor)
				continue ;
			if (raycasting_scene_add_entity(self, descriptor, node->pos)
				== ERROR)
				return ;
		}
	}
}
