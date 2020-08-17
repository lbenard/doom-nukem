/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 20:59:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"
#include "engine/error.h"

static t_result	init_entity_checkbox_entity3(
					t_entity_checkbox_entity *const self)
{
	if (self->super.super.module.has_error)
	{
		destroy_entity_checkbox_entity(self);
		return (throw_result_str("init_entity_checkbox_entity()",
			"failed to create entity checkbox entity"));
	}
	return (OK);
}

static void		init_entity_checkbox_entity2(
					t_entity_checkbox_entity *const self)
{
	frame_layer_transform_add(&self->super.hover_texture,
		&self->entity->icon,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.hover_texture.size.x / 2,
				self->super.hover_texture.size.y / 2),
			ft_vec2f((float)self->super.hover_texture.size.x
				/ (float)self->entity->icon.size.x * 0.7,
				(float)self->super.hover_texture.size.y
					/ (float)self->entity->icon.size.y * 0.7),
			255));
	frame_layer_transform_add(&self->super.checked_texture,
		&self->entity->icon,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.checked_texture.size.x / 2,
				self->super.checked_texture.size.y / 2),
			ft_vec2f((float)self->super.checked_texture.size.x
				/ (float)self->entity->icon.size.x * 0.7,
				(float)self->super.checked_texture.size.y
					/ (float)self->entity->icon.size.y * 0.7),
			255));
}

t_result		init_entity_checkbox_entity(
					t_entity_checkbox_entity *const self,
					t_entity_checkbox_entity_args *const args)
{
	if (static_module_create(self,
		checkbox_entity_base(args->base_name, args->window)) == ERROR)
	{
		return (throw_result_str("init_entity_checkbox_entity()",
			"failed to create parent object"));
	}
	self->entity = args->entity;
	frame_layer_transform_add(&self->super.normal_texture,
		&self->entity->icon,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.normal_texture.size.x / 2,
				self->super.normal_texture.size.y / 2),
			ft_vec2f((float)self->super.normal_texture.size.x
				/ (float)self->entity->icon.size.x * 0.7,
				(float)self->super.normal_texture.size.y
					/ (float)self->entity->icon.size.y * 0.7),
			255));
	init_entity_checkbox_entity2(self);
	return (init_entity_checkbox_entity3(self));
}
