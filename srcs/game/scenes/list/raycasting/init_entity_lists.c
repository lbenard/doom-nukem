/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:21:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/14 14:54:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	init_raycasting_scene_entity_lists(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->sprite_entities, entity_list());
	module_add(&self->super.module, &self->monster_entities, entity_list());
	module_add(&self->super.module, &self->weapon_entities, entity_list());
	module_add(&self->super.module, &self->ammo_entities, entity_list());
}
