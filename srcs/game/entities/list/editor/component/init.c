/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:52:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 17:49:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/component_entity.h"
#include "engine/error.h"

t_result	init_component_entity(t_component_entity *const self,
				t_component_entity_args *const args)
{
	init_entity_default(&self->super, entity_vtable(component_entity_update));
	self->selectable = FALSE;
	self->is_selected = FALSE;
	self->movable = FALSE;
	self->is_moved = FALSE;
	self->color = ft_rgb(127, 127, 127);
	self->selected_color = ft_rgb(127, 127, 127);
	self->dragged_color = ft_rgb(200, 200, 200);
	self->error_color = ft_rgb(255, 84, 84);
	self->vtable = args->vtable;
	return (OK);
}
