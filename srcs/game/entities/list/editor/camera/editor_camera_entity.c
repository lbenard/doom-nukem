/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:31:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 01:02:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_constructor	editor_camera_entity(const float grid_unit,
					const t_frame *const fb,
					t_scene *const editor)
{
	static t_editor_camera_entity_args	args;

	args.grid_unit = grid_unit;
	args.fb = fb;
	args.editor = editor;
	return (ft_constructor(
		init_editor_camera_entity,
		destroy_editor_camera_entity,
		sizeof(t_editor_camera_entity),
		&args));
}
