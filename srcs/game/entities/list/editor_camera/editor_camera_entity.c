/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:31:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 19:10:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_camera_entity.h"

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