/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:32:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 01:36:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_component_entity.h"

t_vec2f	editor_component_entity_camera_pos(
			const t_editor_component_entity *const self,
			const t_editor_camera_entity *const camera)
{
	t_transform	camera_transform;
	t_vec2f		diff;

	camera_transform = camera->super.transform;
	diff.x = (float)-camera_transform.position.x
		+ self->super.transform.position.x;
	diff.y = (float)-camera_transform.position.y
		+ self->super.transform.position.y;
	return (ft_vec2f(
		diff.x * camera_transform.scale.x * camera->grid_unit,
		diff.y * camera_transform.scale.y * camera->grid_unit));
}
