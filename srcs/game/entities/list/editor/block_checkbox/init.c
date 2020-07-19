/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:24:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"
#include "engine/error.h"

t_result	init_block_checkbox_entity(t_block_checkbox_entity *const self,
				const t_block_checkbox_entity_args *const args)
{
	if (static_module_create(self, preview_checkbox_entity(args->base_name,
		&args->block->texture, args->window)) == ERROR)
	{
		return (throw_result_str("init_block_checkbox_entity()",
			"failed to create parent object"));
	}
	self->block = args->block;
	frame_layer_transform_add(&self->super.super.normal_texture,
		&self->block->texture,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.super.normal_texture.size.x / 2,
				self->super.super.normal_texture.size.y / 2),
			ft_vec2f((float)self->super.super.normal_texture.size.x
				/ (float)self->block->texture.size.x * 0.7,
				(float)self->super.super.normal_texture.size.y
					/ (float)self->block->texture.size.y * 0.7),
			255));
	frame_layer_transform_add(&self->super.super.hover_texture,
		&self->block->texture,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.super.hover_texture.size.x / 2,
				self->super.super.hover_texture.size.y / 2),
			ft_vec2f((float)self->super.super.hover_texture.size.x
				/ (float)self->block->texture.size.x * 0.7,
				(float)self->super.super.hover_texture.size.y
					/ (float)self->block->texture.size.y * 0.7),
			255));
	frame_layer_transform_add(&self->super.super.checked_texture,
		&self->block->texture,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->super.super.checked_texture.size.x / 2,
				self->super.super.checked_texture.size.y / 2),
			ft_vec2f((float)self->super.super.checked_texture.size.x
				/ (float)self->block->texture.size.x * 0.7,
				(float)self->super.super.checked_texture.size.y
					/ (float)self->block->texture.size.y * 0.7),
			255));
	if (self->super.super.super.module.has_error)
	{
		destroy_block_checkbox_entity(self);
		return (throw_result_str("init_block_checkbox_entity()",
			"failed to create block checkbox entity"));
	}
	return (OK);
}
