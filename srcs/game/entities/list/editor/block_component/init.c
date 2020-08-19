/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:30:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 17:49:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"
#include "engine/error.h"

t_result	init_block_component_entity(t_block_component_entity *const self,
				t_block_component_entity_args *const args)
{
	if (static_module_create(self, component_entity(
		(struct s_component_entity_vtable){
			block_component_entity_render,
			block_component_entity_is_hovered})) == ERROR)
	{
		return (throw_result_str("init_block_component_entity()",
			"failed to init parent class"));
	}
	self->super.super.vtable.update = block_component_entity_update;
	self->block = args->block;
	self->block_list = args->block_list;
	self->pos_before_move = ft_vec3f(0.0f, 0.0f, 0.0f);
	self->was_not_moved = FALSE;
	if (self->super.super.module.has_error)
	{
		destroy_block_component_entity(self);
		return (throw_result_str("init_block_component_entity()",
			"failed to init block component entity"));
	}
	return (OK);
}
