/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_handler_callback.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:00:49 by mribouch          #+#    #+#             */
/*   Updated: 2020/09/11 09:16:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

void	init_event_handler_callback(t_editor_scene *const self)
{
	event_handler_add_callback(&self->super.input_manager, new_cursor_event());
	event_handler_add_callback(&self->super.input_manager,
		new_block_create_event());
	event_handler_add_callback(&self->super.input_manager,
		new_entity_create_event());
}
