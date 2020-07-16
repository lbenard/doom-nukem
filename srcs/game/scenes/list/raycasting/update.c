/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 03:41:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"
#include "engine/game.h"

void	raycasting_scene_update(t_raycasting_scene *const self)
{
	entity_list_update(&self->super.entities);
	self->weapon.just_shooted = FALSE;
	self->weapon.just_reloaded = FALSE;
	if (input_get(&game_singleton()->input, self->weapon.reload_input) > 0.0f)
		raycasting_scene_weapon_reload(self);
	if (input_get(&game_singleton()->input, self->weapon.shoot_input) > 0.0f)
		raycasting_scene_weapon_use(self);
	// cursor_set_pos(&self->window_ref->cursor, self->window_ref->window,
	// 	ft_isize(self->window_ref->size.x / 2, self->window_ref->size.y / 2));
}
