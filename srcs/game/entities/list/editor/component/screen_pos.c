/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:36:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:15:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/component_entity.h"

t_isize	component_entity_screen_pos(const t_component_entity *const self,
			const t_editor_camera_entity *const camera,
			const t_frame *const screen)
{
	t_vec2f	camera_pos;

	camera_pos = component_entity_editor_camera_pos(self, camera);
	return (ft_isize(camera_pos.x + screen->size.x / 2,
		camera_pos.y + screen->size.y / 2));
}