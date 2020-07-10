/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 21:58:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"
#include "engine/game.h"

void	raycasting_scene_update(t_raycasting_scene *const self)
{
	entity_list_update(&self->super.entities);
	if (input_get(&game_singleton()->input, self->shoot_input) > 0.0f)
		raycasting_scene_shoot(self);
	// cursor_set_pos(&self->window_ref->cursor, self->window_ref->window,
	// 	ft_isize(self->window_ref->size.x / 2, self->window_ref->size.y / 2));
}
