/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_component_entity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:50:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/08 15:26:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"

t_constructor	grid_component_entity(const t_usize frame_size)
{
	static t_grid_component_entity_args	args;

	args.frame_size = frame_size;
	return (ft_constructor(
		init_grid_component_entity,
		destroy_grid_component_entity,
		sizeof(t_grid_component_entity),
		&args));
}