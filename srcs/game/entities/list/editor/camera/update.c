/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:36:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 19:56:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"
#include "engine/delta.h"
#include "engine/game.h"

void	editor_camera_entity_update(t_editor_camera_entity *const self)
{
	t_game	*singleton;

	singleton = game_singleton();
	self->super.transform.position.y -= 2.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->up);
	self->super.transform.position.x += 2.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->right);
	self->super.transform.position.y += 2.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->down);
	self->super.transform.position.x -= 2.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->left);
	(void)self;
}
