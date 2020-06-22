/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:39:22 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/20 19:58:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "engine/error.h"

#include <stdio.h>

t_result	init_sprite_entity(t_sprite_entity *const self,
				t_vec3f pos,
				const char *texture_path,
				t_sprite_entity_vtable vtable)
{
	init_entity(&self->super,
		ft_transform(
			pos,
			ft_vec3f(0.0f, 0.0f, 0.0f),
			ft_vec3f(1.0f, 1.0f, 1.0f)),
		entity_vtable(vtable.sprite_entity_update_fn));
	module_add(&self->super.module, &self->texture,
		frame_from_file(texture_path));
	printf("init sprite texture ptr: %p\n", &self->texture);
	if (self->super.module.has_error)
	{
		destroy_sprite_entity(self);
		return (throw_result_str("init_sprite_entity()",
			"failed to init sprite entity"));
	}
	return (OK);
}