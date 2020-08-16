/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:21:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:39:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

t_result	init_sprite_entity_from(t_sprite_entity *const self,
				t_sprite_entity_args *const args)
{
	init_entity(&self->super,
		ft_transform(
			args->pos,
			ft_vec3f(0.0f, 0.0f, 0.0f),
			ft_vec3f(1.0f, 1.0f, 1.0f)),
		entity_vtable(sprite_entity_update));
	self->ctx = args->ctx;
	module_add(&self->super.module, &self->texture,
		frame(args->from->size, ft_rgba(0, 0, 0, 0)));
	self->player_ref = args->ctx->entities.player_ref;
	self->frame_ref = &args->ctx->window_ref->frame;
	if (self->super.module.has_error)
	{
		destroy_sprite_entity(self);
		return (throw_result_str("init_sprite_entity_from()",
			"failed to init sprite entity"));
	}
	frame_layer_opaque(&self->texture, args->from, ft_isize(0, 0));
	if (!entity_list_add_entity_ref(&args->ctx->sprite_entities, &self->super))
	{
		destroy_sprite_entity(self);
		return (throw_result_str("init_sprite_entity_from()",
			"failed to add entity to list"));
	}
	return (OK);
}
