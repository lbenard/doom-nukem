/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:17:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:05:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

void	ghost_segment_component_entity_render(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			t_frame *const frame)
{
	t_ghost_segment_component_entity	*entity;

	entity = (t_ghost_segment_component_entity*)self;
	(void)camera;
	shape_render(
		&entity->shape,
		ft_isize(0, 0),
		frame,
		ft_rgba(255, 0, 0, 42)
	);
}