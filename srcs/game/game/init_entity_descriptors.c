/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_descriptors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:21:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:42:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/entities/onepunchman_entity.h"
#include "game/entities/weird_alien_entity.h"

void	init_entity_descriptors(t_game *const self)
{
	module_add(&self->module, &self->entities_list.onepunchman,
		entity_descriptor("one_punch_man",
			"resources/sprites/onepunchman-icon.bmp",
			onepunchman_entity));
	module_add(&self->module, &self->entities_list.weird_alien,
		entity_descriptor("weird_alien",
			"resources/sprites/weird_alien_icon.bmp",
			weird_alien_entity));
}