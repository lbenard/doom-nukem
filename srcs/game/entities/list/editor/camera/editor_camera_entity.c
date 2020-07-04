/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:31:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/03 18:02:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_constructor	editor_camera_entity(const float grid_unit,
					const t_frame *const fb,
					t_event_handler *const parent_handler)
{
	static t_editor_camera_entity_args	args;

	args.grid_unit = grid_unit;
	args.fb = fb;
	args.parent = parent_handler;
	return (ft_constructor(
		init_editor_camera_entity,
		destroy_editor_camera_entity,
		sizeof(t_editor_camera_entity),
		&args));
}