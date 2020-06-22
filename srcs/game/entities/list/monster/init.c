/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:24:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/20 19:51:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "engine/error.h"

t_result	init_monster_entity(t_monster_entity *const self,
				const t_monster_entity_args *const args)
{
	if (init_sprite_entity(&self->super,
		ft_vec3f(args->pos.x, args->pos.y, 0.0f),
		args->path,
		sprite_entity_vtable(monster_entity_update)) == ERROR)
	{
		destroy_monster_entity(self);
		return (throw_result_str("init_monster_entity()",
			"failed to init sprite parent"));
	}
	// module_add(&self->super.module, &self->texture,
	// 	frame_from_file(args->path));
	self->health = args->health;
	self->damage = args->damage;
	if (self->super.super.module.has_error == TRUE)
	{
		destroy_monster_entity(self);
		return (throw_result_str("init_monster_entity()",
			"failed to init monster entity"));
	}
	return (OK);
}

