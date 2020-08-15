/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hovered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:12:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 23:34:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"

t_bool	grid_component_entity_is_hovered(t_component_entity *const self,
			t_editor_camera_entity *const camera,
			const t_frame *const frame,
			const t_isize mouse_pos)
{
	(void)self;
	(void)camera;
	(void)frame;
	(void)mouse_pos;
	return (FALSE);
}
