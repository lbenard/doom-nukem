/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_component_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:29:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:25:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_component_entity.h"

t_constructor	entity_component_entity(const t_entity_descriptor *entity,
					const t_entity_list *const entity_list)
{
	static t_entity_component_entity_args	args;

	args.entity = entity;
	args.entity_list = entity_list;
	return (ft_constructor(init_entity_component_entity,
		destroy_entity_component_entity,
		sizeof(t_entity_component_entity),
		&args));
}