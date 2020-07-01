/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:51:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 20:51:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"
#include "engine/error.h"

t_result	init_grid_component_entity(t_grid_component_entity *const self,
				const t_grid_component_entity_args *const args)
{
	
	if (static_module_create(self, component_entity(0,
		(struct s_component_entity_vtable){
			grid_component_entity_render,
			grid_component_entity_is_hovered})) == ERROR)
	{
		return (throw_result_str("init_grid_component_entity()",
			"failed to init editor component entity"));
	}
	self->super.super.transform.scale.x = args->frame_size.x;
	self->super.super.transform.scale.y = args->frame_size.y;
	self->unit_size = args->unit_size;
	if (self->super.super.module.has_error)
	{
		destroy_grid_component_entity(self);
		return (throw_result_str("init_grid_component_entity()",
			"failed to init entity module"));
	}
	return (OK);
}
