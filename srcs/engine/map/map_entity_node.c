/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entity_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:16:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 01:20:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_constructor	map_entity_node(const char *name, const t_vec2f pos)
{
	static t_map_entity_node_args	args;

	args.name = name;
	args.pos = pos;
	return (ft_constructor(init_map_entity_node,
		destroy_map_entity_node,
		sizeof(t_map_entity_node),
		&args));
}
