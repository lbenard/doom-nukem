/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_component_entity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:50:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 20:52:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"

t_constructor	grid_component_entity(const t_usize frame_size,
					const float grid_unit)
{
	static t_grid_component_entity_args	args;

	args.frame_size = frame_size;
	args.unit_size = grid_unit;
	return (ft_constructor(
		init_grid_component_entity,
		destroy_grid_component_entity,
		sizeof(t_grid_component_entity),
		&args));
}
