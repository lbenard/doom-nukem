/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:54:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:40:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"
#include "engine/parsing.h"
#include "ft/str.h"

t_result	map_parse_texture_list(t_map *const self, char *textures_flag_str)
{
	t_texture_node	*new_node;
	char			*p;

	if (!textures_flag_str)
	{
		return (throw_result_str("map_parse_texture_list()",
			"invalid textures string"));
	}
	init_list_head(&self->textures);
	p = ft_skipchr(textures_flag_str, '\n');
	while (*p)
	{
		if (!(new_node = static_module_allocate(texture_node(dn_get_key(p),
			dn_get_value(p)))))
		{
			free(textures_flag_str);
			free_texture_list(&self->textures);
			return (throw_result_str("map_parse_texture_list()",
				"failed to create new texture node"));
		}
		list_add_entry(&new_node->node, &self->textures);
		p = ft_nextline(p);
	}
	free(textures_flag_str);
	return (OK);
}
