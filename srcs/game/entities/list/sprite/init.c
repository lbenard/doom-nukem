/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:39:22 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 21:00:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "engine/error.h"
#include "game/scenes/raycasting_scene.h"

t_result	init_sprite_entity(t_sprite_entity *const self,
				t_sprite_entity_args *const args)
{
	init_entity(&self->super,
		ft_transform(
			args->pos,
			ft_vec3f(0.0f, 0.0f, 0.0f),
			ft_vec3f(1.0f, 1.0f, 1.0f)),
		entity_vtable(sprite_entity_update));
	module_add(&self->super.module, &self->texture,
		frame_from_file(args->texture_path));
	self->player_ref = args->ctx->player_ref;
	self->frame_ref = &args->ctx->window_ref->frame;
	if (self->super.module.has_error)
	{
		destroy_sprite_entity(self);
		return (throw_result_str("init_sprite_entity()",
			"failed to init sprite entity"));
	}
	entity_list_add_entity_ref(&args->ctx->sprite_entities, &self->super);
	return (OK);
}