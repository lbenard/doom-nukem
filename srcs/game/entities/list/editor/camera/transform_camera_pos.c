/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_camera_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:05:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 20:05:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_vec2f	transform_camera_pos(const t_transform transform,
			const t_editor_camera_entity *const camera)
{
	t_transform	camera_transform;
	t_vec2f		diff;

	camera_transform = camera->super.transform;
	diff.x = (float)-camera_transform.position.x + transform.position.x;
	diff.y = (float)-camera_transform.position.y + transform.position.y;
	return (ft_vec2f(
		diff.x * camera_transform.scale.x * camera->grid_unit,
		diff.y * camera_transform.scale.y * camera->grid_unit));
}