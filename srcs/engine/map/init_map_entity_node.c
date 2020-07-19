/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_entity_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:17:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 01:21:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_result	init_map_entity_node(t_map_entity_node *const self,
				const t_map_entity_node_args *const args)
{
	init_module(&self->module);
	init_list_head(&self->node);
	self->name = args->name;
	self->pos = args->pos;
	return (OK);
}
