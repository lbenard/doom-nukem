/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_screen_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:02:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 20:06:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_isize	transform_screen_pos(const t_transform transform,
			const t_editor_camera_entity *const camera,
			const t_frame *const screen)
{
	t_vec2f	camera_pos;

	camera_pos = transform_camera_pos(transform, camera);
	return (ft_isize(camera_pos.x + screen->size.x / 2,
		camera_pos.y + screen->size.y / 2));
}
