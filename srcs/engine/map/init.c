/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:04:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "maths/vec2d.h"
#include "engine/error.h"
#include "engine/parsing.h"

t_result	init_map_split(t_map *const self, char *map_file_str)
{
	if (!map_parse_size(self, dn_select_flag(map_file_str, "size")))
	{
		free(map_file_str);
		free_texture_list(&self->textures);
		free_block_list(&self->blocks);
		return (throw_result_str("init_map()", "failed to parse size"));
	}
	if (!map_parse_map(self, dn_select_flag(map_file_str, "map")))
	{
		free(map_file_str);
		free_texture_list(&self->textures);
		free_block_list(&self->blocks);
		return (throw_result_str("init_map()", "failed to parse map"));
	}
	if (!map_parse_player(self, dn_select_flag(map_file_str, "player")))
	{
		free(map_file_str);
		free_texture_list(&self->textures);
		free_block_list(&self->blocks);
		free(self->map);
		return (throw_result_str("init_map()", "failed to parse player"));
	}
	return (OK);
}

t_result	init_map(t_map *const self, const t_map_args *const args)
{
	char	*map_file_str;

	init_module(&self->module);
	if (!(map_file_str = dn_read_file(args->path)))
		return (throw_result_str("init_map()", "failed to read file"));
	if (!map_parse_texture_list(self,
		dn_select_flag(map_file_str, "textures")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse textures"));
	}
	if (!map_parse_block_list(self, dn_select_flag(map_file_str, "blocks")))
	{
		free(map_file_str);
		free_texture_list(&self->textures);
		return (throw_result_str("init_map()", "failed to parse blocks"));
	}
	if (init_map_split(self, map_file_str) == ERROR)
		return (ERROR);
	free(map_file_str);
	return (OK);
}
