/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_block_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:02:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:57:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"
#include "engine/parsing.h"
#include "ft/str.h"

t_result	map_parse_block_list(t_map *const self, char *blocks_flag_str)
{
	t_block_node	*new_node;
	char			*p;

	if (!blocks_flag_str)
	{
		return (throw_result_str("map_parse_block_list()",
			"invalid blocks string"));
	}
	init_list_head(&self->blocks);
	p = ft_skipchr(blocks_flag_str, '\n');
	while (*p)
	{
		if (!(new_node = static_module_allocate(block_node(dn_get_key(p),
			dn_get_values(p, ' ')))))
		{
			free(blocks_flag_str);
			free_block_list(&self->blocks);
			return (throw_result_str("map_parse_block_list()",
				"failed to create new block node"));
		}
		list_add_entry(&new_node->node, &self->blocks);
		p = ft_nextline(p);
	}
	free(blocks_flag_str);
	return (OK);
}
