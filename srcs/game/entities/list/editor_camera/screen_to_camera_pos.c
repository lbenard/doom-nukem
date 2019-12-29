/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_to_camera_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:23:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/29 21:22:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_camera_entity.h"

#include <stdio.h>

t_vec2f	editor_camera_entity_screen_to_camera_pos(
			const t_editor_camera_entity *const self,
			const t_frame *const screen,
			const t_isize pos)
{
	t_vec2f	ret;

	ret.x = ((float)pos.x - screen->size.x / 2.0f)
		/ self->grid_unit
		/ self->super.transform.scale.x
		+ self->super.transform.position.x;
	ret.y = ((float)pos.y - screen->size.y / 2.0f)
		/ self->grid_unit
		/ self->super.transform.scale.y
		+ self->super.transform.position.y;
	return (ret);
}