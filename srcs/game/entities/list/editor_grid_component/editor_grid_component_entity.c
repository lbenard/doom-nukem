/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_grid_component_entity.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:50:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 17:55:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_grid_component_entity.h"

t_constructor	editor_grid_component_entity(const t_usize frame_size)
{
	static t_editor_grid_component_entity_args	args;

	args.frame_size = frame_size;
	return (ft_constructor(
		init_editor_grid_component_entity,
		destroy_editor_grid_component_entity,
		sizeof(t_editor_grid_component_entity),
		&args));
}