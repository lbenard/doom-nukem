/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:45:07 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/15 22:52:22 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"
#include "engine/error.h"

t_result		init_fireball_entity(t_fireball_entity *const self,
					const t_fireball_entity_args *const args)
{
	t_raycasting_scene	*scene;

	scene = (t_raycasting_scene*)game_singleton()->scene;
	if (static_module_create(self,
		sprite_entity_size(args->pos,
			scene->assets.fireball_spritesheet.sprite_size,
			scene)) == ERROR)
	{
		return (throw_result_str("init_fireball_entity()",
			"failed to create fireball entity"));
	}
	self->spritesheet_ref = &scene->assets.fireball_spritesheet;
	module_add(&self->super.super.module,
		&self->anim.module, animation(0, 6, 0.8f));
	self->super.super.transform.position = args->pos;
	self->super.super.transform.position.z = 0.3f;
	self->super.super.transform.direction = args->direction;
	self->super.super.transform.scale.x = 0.2f;
	self->super.super.transform.scale.y = 0.2f;
	self->super.super.vtable.update = fireball_entity_update;
	self->map_ref = &scene->map;
	self->damage = 50;
	return (OK);
}
