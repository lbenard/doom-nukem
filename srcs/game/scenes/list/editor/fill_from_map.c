/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_from_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:09:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:52:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/map.h"

static void	fill_blocks(t_editor_scene *const self,
				const t_map *const input_map)
{
	t_game				*game;
	t_usize				i;
	char				id;
	t_block_descriptor	*bd;

	game = game_singleton();
	i.y = 0;
	while (i.y < input_map->size.y)
	{
		i.x = 0;
		while (i.x < input_map->size.x)
		{
			if ((id = input_map->map[i.y * input_map->size.x + i.x].id) != ' ')
			{
				bd = block_descriptor_from_id(
					(t_block_descriptor*)&game->blocks_list,
					sizeof(game->blocks_list) / sizeof(t_block_descriptor), id);
				if (bd)
					editor_scene_add_block(self, bd, ft_vec2f(i.x, i.y));
			}
			i.x++;
		}
		i.y++;
	}
}

static void	fill_entities(t_editor_scene *const self,
				const t_map *const input_map)
{
	t_game						*game;
	const t_list_head			*pos;
	const t_map_entity_node		*node;
	const t_entity_descriptor	*ed;

	game = game_singleton();
	pos = &input_map->entities;
	while ((pos = pos->next) != &input_map->entities)
	{
		node = (t_map_entity_node*)((t_u8*)pos
			- __builtin_offsetof(t_map_entity_node, node));
		ed = entity_descriptor_from_name(
			(t_entity_descriptor*)&game->entities_list,
			sizeof(game->entities_list) / sizeof(t_entity_descriptor),
			node->name);
		if (ed)
			editor_scene_add_entity(self, ed, node->pos);
	}
}

t_result	fill_from_map(t_editor_scene *const self, const char *const path)
{
	t_map	input_map;

	if (static_module_create(&input_map, map(path)) == ERROR)
		return (ERROR);
	fill_blocks(self, &input_map);
	fill_entities(self, &input_map);
	self->player_spawn_ref->super.super.transform.position = ft_vec3f(
		input_map.spawn.x, input_map.spawn.y, 0.0f);
	destroy_map(&input_map);
	if (self->super.module.has_error)
		return (ERROR);
	return (OK);
}
