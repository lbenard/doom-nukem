/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_camera_pos_to_screen.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:14:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 20:04:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"

t_isize	editor_camera_entity_editor_camera_pos_to_screen(
			const t_editor_camera_entity *const self,
			const t_frame *const screen,
			const t_vec2f pos)
{
	(void)self;
	return (ft_isize(pos.x + screen->size.x / 2,
		pos.y + screen->size.y / 2));
}
