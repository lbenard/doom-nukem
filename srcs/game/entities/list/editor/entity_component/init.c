/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:30:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:25:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_component_entity.h"
#include "engine/error.h"

t_result	init_entity_component_entity(t_entity_component_entity *const self,
				t_entity_component_entity_args *const args)
{
	if (static_module_create(self, component_entity(0,
		(struct s_component_entity_vtable){
			entity_component_entity_render,
			entity_component_entity_is_hovered})) == ERROR)
	{
		return (throw_result_str("init_entity_component_entity()",
			"failed to init parent class"));
	}
	self->super.super.vtable.update = entity_component_entity_update;
	self->entity = args->entity;
	self->entity_list = args->entity_list;
	if (self->super.super.module.has_error)
	{
		destroy_entity_component_entity(self);
		return (throw_result_str("init_entity_component_entity()",
			"failed to init entity component entity"));
	}
	return (OK);
}
