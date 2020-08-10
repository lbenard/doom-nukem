/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:24:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 17:33:23 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "ft/str.h"

static t_result	init_add_module(t_monster_entity *const self,
					const t_monster_entity_args *const args)
{
	module_add(&self->super.super.module, &self->animation,
		animation(0, args->spritesheet_ref->nb_sprite, 1.0f));
	module_add(&self->super.super.module, &self->name_text,
		text("haxorville.bmp",
			ft_usize(5 * ft_strlen(args->name), 9)));
	if (self->super.super.module.has_error == TRUE)
	{
		destroy_monster_entity(self);
		return (throw_result_str("init_monster_entity()",
			"failed to init monster entity"));
	}
	return (OK);
}

static void		init_vars(t_monster_entity *const self,
				const t_monster_entity_args *const args)
{
	self->super.super.vtable.update = monster_entity_update;
	self->spritesheet_ref = args->spritesheet_ref;
	self->player_ref = args->ctx->player_ref;
	self->full_health = args->health;
	self->health = args->health;
	self->damage = args->damage;
	self->name = args->name;
	self->is_star = FALSE;
	self->super.super.transform.direction = ft_vec3f(0, 1, 0);
	self->agro = FALSE;
	self->distance_agro = 30;
	self->max_distance_agro = 50;
}

t_result		init_monster_entity(t_monster_entity *const self,
				const t_monster_entity_args *const args)
{
	if (static_module_create(self, sprite_entity_size(
		ft_vec3f(args->pos.x, args->pos.y, 0.0f),
		args->spritesheet_ref->sprite_size, args->ctx))
		== ERROR)
	{
		return (throw_result_str("init_monster_entity()",
			"failed to create parent class"));
	}
	if (!entity_list_add_entity_ref(&args->ctx->monster_entities,
		(t_entity*)self))
	{
		destroy_monster_entity(self);
		return (throw_result_str("init_monster_entity()",
			"failed to add monster to list"));
	}
	init_vars(self, args);
	init_add_module(self, args);
	text_set_ref(&self->name_text,
		static_string_as_ref(ft_static_string(self->name)));
	text_render(&self->name_text, ft_text_settings(ft_isize(0, 0), 9));
	frame_fill_blend(&self->name_text.target, ft_rgba(255, 255, 255, 255),
		blend_colorize);
	return (OK);
}
