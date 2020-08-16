/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:17:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/13 13:22:51 by lbenard          ###   ########.fr       */
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

static t_result	write_map_size(const int fd, const t_usize size)
{
	errno = 0;
	ft_putstr_fd("-size\n", fd);
	ft_putstr_fd("height: ", fd);
	ft_putnbr_fd((int)size.y, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("width: ", fd);
	ft_putnbr_fd((int)size.x, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}

static t_result	write_player_spawn(const int fd,
					const t_player_component_entity *const player,
					const t_isize origin)
{
	errno = 0;
	ft_putstr_fd("-player\n", fd);
	ft_putstr_fd("spawn: ", fd);
	ft_putfloat_fd(player->super.super.transform.position.x - origin.x, fd);
	ft_putchar_fd(' ', fd);
	ft_putfloat_fd(player->super.super.transform.position.y - origin.y, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}

static t_result	write_entities(t_editor_scene *const self,
					const int fd,
					const t_isize origin)
{
	t_list_head					*pos;
	t_entity_component_entity	*entity;

	errno = 0;
	pos = &self->entities.list;
	ft_putstr_fd("-entities\n", fd);
	while ((pos = pos->next) != &self->entities.list)
	{
		entity = (t_entity_component_entity*)((t_entity_node*)pos)->entity;
		ft_putstr_fd(entity->entity->name, fd);
		ft_putstr_fd(": ", fd);
		ft_putfloat_fd(entity->super.super.transform.position.x
			- (float)origin.x, fd);
		ft_putchar_fd(' ', fd);
		ft_putfloat_fd(entity->super.super.transform.position.y
			- (float)origin.y, fd);
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_size()"));
	return (OK);
}

static t_result	write_map(t_editor_scene *const self,
					const int fd,
					const t_isize origin,
					const t_usize size)
{
	t_usize						i;
	char						**map;
	t_list_head					*pos;
	t_block_component_entity	*block;
	int							ret;

	(void)ret;
	if (!(map = (char**)malloc(sizeof(char*) * size.y)))
		return (ERROR);
	i.y = 0;
	while (i.y < size.y)
	{
		if (!(map[i.y] = (char*)malloc(sizeof(char) * size.x)))
		{
			while (i.y)
				free(map[--i.y]);
			free(map);
			return (ERROR);
		}
		ft_memset(map[i.y], ' ', size.x);
		i.y++;
	}
	pos = &self->blocks.list;
	while ((pos = pos->next) != &self->blocks.list)
	{
		block = (t_block_component_entity*)((t_entity_node*)pos)->entity;
		map[(int)block->super.super.transform.position.y - origin.y]
			[(int)block->super.super.transform.position.x - origin.x] =
			block->block->id;
	}
	errno = 0;
	i.y = 0;
	ft_putstr_fd("-map\n", fd);
	while (i.y < size.y)
	{
		ft_putstr_fd(": ", fd);
		ret = write(fd, map[i.y], size.x);
		ft_putchar_fd('\n', fd);
		i.y++;
	}
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_blocks()"));
	return (OK);
}

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
	{
		return (throw_result_str("editor_export_map()",
			"map has no blocks"));
	}
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
