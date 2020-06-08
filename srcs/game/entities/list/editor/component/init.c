/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:52:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 02:03:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/component_entity.h"
#include "engine/error.h"

t_result	init_component_entity(t_component_entity *const self,
				const t_component_type type,
				const struct s_component_entity_vtable vtable)
{
	init_entity_default(&self->super, entity_vtable(component_entity_update));
	self->type = type;
	self->selectable = FALSE;
	init_list_head(&self->selection_node);
	self->movable = FALSE;
	self->is_moved = FALSE;
	self->color = ft_rgb(127, 127, 127);
	self->selected_color = ft_rgb(127, 127, 127);
	self->dragged_color = ft_rgb(200, 200, 200);
	self->error_color = ft_rgb(255, 84, 84);
	self->vtable = vtable;
	return (TRUE);
}