/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 23:44:38 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/24 20:05:03 by lbenard          ###   ########.fr       */
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

static void	free_map(char **map, const t_usize size)
{
	size_t	i;

	i = 0;
	while (i < size.y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**create_map(const t_usize size)
{
	char	**map;
	t_usize	i;

	if (!(map = (char**)malloc(sizeof(char*) * size.y)))
		return (throw_error_str("create_map()", "failed to allocate rows"));
	i.y = 0;
	while (i.y < size.y)
	{
		if (!(map[i.y] = (char*)malloc(sizeof(char) * size.x)))
		{
			while (i.y)
				free(map[--i.y]);
			free(map);
			return (throw_error_str("create_map()", "failed to allocate line"));
		}
		ft_memset(map[i.y], ' ', size.x);
		i.y++;
	}
	return (map);
}

static void	fill_map(t_editor_scene *const self,
				char **map,
				const t_isize origin)
{
	t_list_head					*pos;
	t_block_component_entity	*block;

	pos = &self->blocks.list;
	while ((pos = pos->next) != &self->blocks.list)
	{
		block = (t_block_component_entity*)((t_entity_node*)pos)->entity;
		map[(int)block->super.super.transform.position.y - origin.y]
			[(int)block->super.super.transform.position.x - origin.x] =
			block->block->id;
	}
}

t_result	write_map(t_editor_scene *const self,
					const int fd,
					const t_isize origin,
					const t_usize size)
{
	char	**map;
	size_t	i;
	int		ret;

	if (!(map = create_map(size)))
		return (throw_result_str("write_map()", "failed to create map array"));
	fill_map(self, map, origin);
	errno = 0;
	i = 0;
	ft_putstr_fd("-map\n", fd);
	(void)ret;
	while (i < size.y)
	{
		ft_putstr_fd(": ", fd);
		ret = write(fd, map[i], size.x);
		ft_putchar_fd('\n', fd);
		i++;
	}
	free_map(map, size);
	ft_putchar_fd('\n', fd);
	if (errno)
		return (throw_result("write_blocks()"));
	return (OK);
}
