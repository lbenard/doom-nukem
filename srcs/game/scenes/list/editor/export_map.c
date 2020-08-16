/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:17:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/17 00:09:44 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "game/scenes/editor_scene.h"
#include "game/entities/editor/block_component_entity.h"
#include "game/entities/editor/entity_component_entity.h"
#include "engine/error.h"
#include "game/game.h"
#include "ft/str.h"
#include "ft/io.h"
#include "ft/mem.h"

static t_isize	blocks_origin(t_editor_scene *const self)
{
	t_list_head					*pos;
	t_block_component_entity	*block;
	t_bool						is_init;
	t_isize						block_pos;

	pos = &self->blocks.list;
	is_init = FALSE;
	while ((pos = pos->next) != &self->blocks.list)
	{
		block = (t_block_component_entity*)((t_entity_node*)pos)->entity;
		if (!is_init)
		{
			block_pos = ft_isize(block->super.super.transform.position.x,
				block->super.super.transform.position.y);
			is_init = TRUE;
			continue ;
		}
		if (block->super.super.transform.position.x < block_pos.x)
			block_pos.x = block->super.super.transform.position.x;
		if (block->super.super.transform.position.y < block_pos.y)
			block_pos.y = block->super.super.transform.position.y;
	}
	return (block_pos);
}

static t_usize	get_map_size(t_editor_scene *const self,
					const t_isize origin)
{
	t_list_head					*pos;
	t_block_component_entity	*block;
	t_bool						is_init;
	t_isize						block_pos;

	pos = &self->blocks.list;
	is_init = FALSE;
	block_pos = origin;
	while ((pos = pos->next) != &self->blocks.list)
	{
		block = (t_block_component_entity*)((t_entity_node*)pos)->entity;
		if (!is_init)
		{
			block_pos = ft_isize(block->super.super.transform.position.x,
				block->super.super.transform.position.y);
			is_init = TRUE;
			continue ;
		}
		if (block->super.super.transform.position.x > block_pos.x)
			block_pos.x = block->super.super.transform.position.x;
		if (block->super.super.transform.position.y > block_pos.y)
			block_pos.y = block->super.super.transform.position.y;
	}
	return (ft_usize((size_t)block_pos.x - origin.x + 1,
		(size_t)block_pos.y - origin.y + 1));
}

t_result		editor_scene_export_map(t_editor_scene *const self)
{
	int		fd;
	t_isize	origin;
	t_usize	size;

	if (list_size(&self->blocks.list) == 0)
		return (throw_result_str("editor_export_map()", "map has no blocks"));
	if ((fd = open(self->path, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1)
		return (throw_result("editor_export_map()"));
	origin = blocks_origin(self);
	size = get_map_size(self, origin);
	if (size.x < 3 || size.y < 3)
	{
		return (throw_result_str("editor_export_map()",
			"map is too small"));
	}
	if (!write_map_size(fd, size))
		return (throw_result("editor_export_map()"));
	if (!write_player_spawn(fd, self->player_spawn_ref, origin))
		return (throw_result("editor_export_map()"));
	if (!write_entities(self, fd, origin))
		return (throw_result("editor_export_map()"));
	if (!write_map(self, fd, origin, size))
		return (throw_result("editor_export_map()"));
	return (OK);
}
