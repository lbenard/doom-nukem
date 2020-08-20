/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_descriptors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:21:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/20 18:06:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/entities/widepunchman_entity.h"
#include "game/entities/weird_alien_entity.h"
#include "game/entities/ghast_entity.h"
#include "game/entities/nyarlathotep_entity.h"
#include "game/entities/pistol_entity.h"
#include "game/entities/shotgun_entity.h"
#include "game/entities/minigun_entity.h"
#include "game/entities/ammo_entity.h"
#include "game/entities/medikit_entity.h"

static void	module_add_weapon(t_game *const self)
{
	module_add(&self->module, &self->entities_list.pistol,
		entity_descriptor("pistol",
			"resources/sprites/pistol-sprite.bmp",
			pistol_entity));
	module_add(&self->module, &self->entities_list.shotgun,
		entity_descriptor("shotgun",
			"resources/sprites/shotgun-sprite.bmp",
			shotgun_entity));
	module_add(&self->module, &self->entities_list.minigun,
		entity_descriptor("minigun",
			"resources/sprites/minigun-sprite.bmp",
			minigun_entity));
	module_add(&self->module, &self->entities_list.ammo,
		entity_descriptor("ammo",
			"resources/sprites/ammo-sprite.bmp",
			ammo_entity));
	module_add(&self->module, &self->entities_list.medikit,
		entity_descriptor("medikit",
			"resources/sprites/medikit-sprite.bmp",
			medikit_entity));
}

void		init_entity_descriptors(t_game *const self)
{
	module_add(&self->module, &self->entities_list.widepunchman,
		entity_descriptor("wide_punch_man",
			"resources/sprites/widepunchman-icon.bmp",
			widepunchman_entity));
	module_add(&self->module, &self->entities_list.weird_alien,
		entity_descriptor("weirdalien",
			"resources/sprites/weirdalien-icon.bmp",
			weird_alien_entity));
	module_add(&self->module, &self->entities_list.ghast,
		entity_descriptor("ghast",
			"resources/sprites/ghast-icon.bmp",
			ghast_entity));
	module_add(&self->module, &self->entities_list.nyarlathotep,
		entity_descriptor("nyarlathotep",
			"resources/sprites/nyarlathotep-icon.bmp",
			nyarlathotep_entity));
	module_add_weapon(self);
}
