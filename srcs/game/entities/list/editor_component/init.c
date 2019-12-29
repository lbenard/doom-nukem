/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:52:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/25 20:44:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_component_entity.h"
#include "engine/error.h"

t_result	init_editor_component_entity(t_editor_component_entity *const self,
				const t_editor_component_type type,
				const struct s_editor_component_entity_vtable vtable)
{
	if (init_entity_default(&self->super,
		entity_vtable(editor_component_entity_update)) == ERROR)
	{
		return (throw_result_str("init_editor_component_entity()",
			"failed to init entity"));
	}
	self->type = type;
	self->selectable = FALSE;
	self->is_selected = FALSE;
	self->movable = FALSE;
	self->is_moved = FALSE;
	self->color = ft_rgb(127, 127, 127);
	self->selected_color = ft_rgb(127, 127, 127);
	self->dragged_color = ft_rgb(200, 200, 200);
	self->error_color = ft_rgb(255, 84, 84);
	self->vtable = vtable;
	return (TRUE);
}