/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:45:07 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 17:54:47 by mribouch         ###   ########.fr       */
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
		sprite_entity(args->pos, args->texture_path, scene)) == ERROR)
	{
		return (throw_result_str("init_fireball_entity()",
			"failed to create fireball entity"));
	}
	self->super.super.transform.position = args->pos;
	self->super.super.transform.direction = args->direction;
	self->damage = 50;
	self->super.super.vtable.update = fireball_entity_update;
	return (OK);
}
