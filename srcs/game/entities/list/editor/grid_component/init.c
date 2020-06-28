/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:51:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/23 19:41:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"
#include "engine/error.h"

t_result	init_grid_component_entity(t_grid_component_entity *const self,
				const t_grid_component_entity_args *const args)
{
	if (init_entity_default(&self->super,
		entity_vtable(grid_component_entity_update)) == ERROR)
	{
		return (throw_result_str("init_grid_component_entity()",
			"failed to init editor component entity"));
	}
	self->super.transform.scale.x = args->frame_size.x;
	self->super.transform.scale.y = args->frame_size.y;
	self->unit_size = args->frame_size.y * 0.2f;
	if (self->super.module.has_error)
	{
		destroy_grid_component_entity(self);
		return (throw_result_str("init_grid_component_entity()",
			"failed to init entity module"));
	}
	return (OK);
}
