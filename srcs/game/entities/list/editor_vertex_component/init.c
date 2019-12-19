/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:37:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:11:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"
#include "engine/error.h"

t_result	init_editor_vertex_component_entity(
				t_editor_vertex_component_entity *const self,
				const t_editor_vertex_component_entity_args *const args)
{
	if (init_editor_component_entity(&self->super, VERTEX,
		(struct s_editor_component_entity_vtable){
			editor_vertex_component_entity_render,
			editor_vertex_component_entity_is_selected}) == ERROR)
	{
		return (throw_result_str("init_editor_vertex_component_entity()",
			"failed to init editor component entity"));
	}
	self->super.super.transform.position.x = args->position.x;
	self->super.super.transform.position.y = args->position.y;
	self->vertex_ref = args->vertex_ref;
	self->vertex_selected_ref = args->vertex_selected_ref;
	if (self->super.super.module.has_error)
	{
		destroy_editor_vertex_component_entity(self);
		return (throw_result_str("init_editor_vertex_component_entity()",
			"failed to init editor vertex component entity module"));
	}
	return (OK);
}
