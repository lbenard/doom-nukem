/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:51:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/14 01:13:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"
#include "engine/error.h"

t_result	init_grid_component_entity(t_grid_component_entity *const self,
				const t_grid_component_entity_args *const args)
{
	if (init_component_entity(&self->super, GRID,
		(struct s_component_entity_vtable){
			grid_component_entity_render,
			grid_component_entity_is_hovered}) == ERROR)
	{
		return (throw_result_str("init_grid_component_entity()",
			"failed to init editor component entity"));
	}
	self->super.color = ft_rgb(120, 120, 120);
	self->unit_size = args->frame_size.y * 0.2f;
	if (self->super.super.module.has_error)
	{
		destroy_grid_component_entity(self);
		return (throw_result_str("init_grid_component_entity()",
			"failed to init entity module"));
	}
	return (OK);
}