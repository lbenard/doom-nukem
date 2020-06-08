/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:06:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/22 18:53:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"
#include "engine/error.h"

t_result	init_ghost_segment_component_entity_pos(
				t_ghost_segment_component_entity *const self,
				const t_ghost_segment_component_entity_args *const args)
{
	if (init_component_entity(&self->super, SEGMENT,
		(struct s_component_entity_vtable) {
			ghost_segment_component_entity_render,
			ghost_segment_component_entity_is_hovered}) == ERROR)
	{
		return (throw_result_str("init_ghost_segment_component_entity()",
			"failed to init ghost segment component entity"));
	}
	self->super.super.vtable.update = ghost_segment_component_entity_update;
	self->super.super.transform.position.x = args->start_pos.x;
	self->super.super.transform.position.y = args->start_pos.y;
	self->camera_ref = args->camera_ref;
	self->screen_ref = args->screen_ref;
	module_add(&self->super.super.module, &self->shape, shape());
	self->a = component_entity_screen_pos(
		&self->super,
		self->camera_ref,
		&self->screen_ref->frame
	);
	self->b = self->a;
	self->vertex_ref = NULL;
	shape_push_vertex(&self->shape, new_vertex_node(self->a));
	shape_push_vertex(&self->shape, new_vertex_node(self->a));
	shape_push_vertex(&self->shape, new_vertex_node(self->a));
	shape_push_vertex(&self->shape, new_vertex_node(self->a));
	if (self->super.super.module.has_error || self->shape.module.has_error)
	{
		destroy_ghost_segment_component_entity(self);
		return (throw_result_str("init_ghost_segment_component_entity_pos()",
			"failed to init ghost segment component module"));
	}
	return (OK);
}