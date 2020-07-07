/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:08:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 00:07:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"
#include "engine/parsing.h"
#include "ft/str.h"
#include "ft/mem.h"

static t_result	wall_from_block(t_list_head *const textures,
					t_wall *const wall,
					t_block_node *const block)
{
	t_texture_node	*texture;

	if (!(texture = texture_from_key(textures, block->texture_path)))
		return (throw_result_str("wall_from_block()", "bad texture value"));
	wall->texture_ref = &texture->texture;
	return (OK);
}

static t_result	fill_wall_from_char(t_map *const self,
					t_wall *const wall,
					const char c)
{
	t_block_node	*block;

	if (c == ' ')
		wall->texture_ref = NULL;
	else if ((block = block_from_key(&self->blocks, c)))
		wall_from_block(&self->textures, wall, block);
	else
	{
		return (throw_result_str("fill_wall_from_char()",
			"cannot find block from key"));
	}
	return (OK);
}

static t_result	fill_map_row(t_map *self, char *row, int y)
{
	size_t	x;

	if (!row)
		return (throw_result_str("fill_map_row()", "invalid row string"));
	if (ft_strlen(row) != self->size.x)
	{
		free(row);
		return (throw_result_str("fill_map_row()",
			"bad number of characters in map row"));
	}
	x = 0;
	while (row[x])
	{
		if (fill_wall_from_char(self, &self->map[x + y * self->size.x], row[x])
			== ERROR)
		{
			free(row);
			return (throw_result_str("fill_map_row()",
				"failed to create wall from char"));
		}
		x++;
	}
	free(row);
	return (OK);
}

static t_result	parse(t_map *const self, char *map_flag_str, char *p)
{
	size_t	columns_amount;

	columns_amount = 0;
	while (*p)
	{
		if (columns_amount >= self->size.y ||
			!fill_map_row(self, dn_get_value(p), columns_amount++))
		{
			free(map_flag_str);
			free(self->map);
			return (throw_result_str("map_parse_map()", "failed parse row"));
		}
		p = ft_nextline(p);
	}
	free(map_flag_str);
	if (columns_amount < self->size.y)
	{
		free(self->map);
		return (throw_result_str("map_parse_map()", "not enough lines"));
	}
	return (OK);
}

t_result		map_parse_map(t_map *const self, char *map_flag_str)
{
	char	*p;

	if (!map_flag_str)
		return (throw_result_str("map_parse_map()", "invalid map flag string"));
	if (!(self->map = (t_wall*)malloc(sizeof(t_wall)
		* (self->size.x * self->size.y))))
	{
		free(map_flag_str);
		return (throw_result_str("map_parse_map()", "failed to allocate map"));
	}
	p = ft_skipchr(map_flag_str, '\n');
	return (parse(self, map_flag_str, p));
}
