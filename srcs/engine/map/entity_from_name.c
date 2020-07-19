/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_from_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:19:44 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 01:25:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "ft/str.h"

t_map_entity_node	*entity_from_name(t_list_head *const self,
						const char *name)
{
	t_list_head			*pos;
	t_map_entity_node	*entity;

	pos = self;
	while ((pos = pos->next) != self)
	{
		entity = (t_map_entity_node*)((t_u8*)pos
			- __builtin_offsetof(t_map_entity_node, node));
		if (!ft_strcmp(entity->name, name))
			return (entity);
	}
	return (NULL);
}
