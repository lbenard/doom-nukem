/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:45:07 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 14:41:51 by lbenard          ###   ########.fr       */
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
			scene->assets.fireball.size,
			scene)) == ERROR)
	{
		return (throw_result_str("init_fireball_entity()",
			"failed to create fireball entity"));
	}
	frame_layer_opaque(&self->super.texture,
		&scene->assets.fireball,
		ft_isize(0, 0));
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
