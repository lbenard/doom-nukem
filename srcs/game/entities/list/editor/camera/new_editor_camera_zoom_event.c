/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_editor_camera_zoom_event.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:32:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"
#include "engine/error.h"
#include "engine/input.h"
#include "game/game.h"

t_callback_node	*new_editor_camera_zoom_event(const t_frame *const fb)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(editor_camera_zoom_event, (void*)fb)))
	{
		return (throw_error_str("editor_camera_zoom_event()",
			"failed to create new editor camera zoom event"));
	}
	return (node);
}
