/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_descriptors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:21:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 04:24:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/entities/onepunchman_entity.h"
#include "game/entities/weird_alien_entity.h"
#include "game/entities/ghast_entity.h"
#include "game/entities/nyarlathotep_entity.h"
#include "game/entities/pistol_entity.h"
#include "game/entities/shotgun_entity.h"
#include "game/entities/minigun_entity.h"

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
	module_add(&self->module, &self->entities_list.ghast,
		entity_descriptor("ghast",
			"resources/sprites/ghast_icon.bmp",
			ghast_entity));
	module_add(&self->module, &self->entities_list.nyarlathotep,
		entity_descriptor("nyarlathotep",
			"resources/sprites/nyarlathotep_icon.bmp",
			nyarlathotep_entity));
	module_add(&self->module, &self->entities_list.pistol,
		entity_descriptor("pistol",
			"resources/sprites/pistol_sprite.bmp",
			pistol_entity));
	module_add(&self->module, &self->entities_list.shotgun,
		entity_descriptor("shotgun",
			"resources/sprites/shotgun_sprite.bmp",
			shotgun_entity));
	module_add(&self->module, &self->entities_list.minigun,
		entity_descriptor("minigun",
			"resources/sprites/minigun_sprite.bmp",
			minigun_entity));
}
