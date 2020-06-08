/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:31:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 19:26:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_constructor	editor_camera_entity(const float grid_unit)
{
	static t_editor_camera_entity_args	args;

	args.grid_unit = grid_unit;
	return (ft_constructor(
		init_editor_camera_entity,
		destroy_editor_camera_entity,
		sizeof(t_editor_camera_entity),
		&args));
}