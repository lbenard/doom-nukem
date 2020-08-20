/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:59:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/20 18:40:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/entities/checkbox_entity.h"

static void	add_modules(t_checkbox_entity *const self,
				const t_checkbox_entity_args *const args)
{
	module_add(&self->super.module, &self->normal_texture,
		frame_from_file(args->normal_texture_path));
	module_add(&self->super.module, &self->hover_texture,
		frame_from_file(args->hover_texture_path));
	module_add(&self->super.module, &self->checked_texture,
		frame_from_file(args->checked_texture_path));
}

t_result	init_checkbox_entity(t_checkbox_entity *const self,
				const t_checkbox_entity_args *const args)
{
	init_entity_default(&self->super, entity_vtable(checkbox_entity_update));
	add_modules(self, args);
	self->current_texture = &self->normal_texture;
	self->is_checked = FALSE;
	self->window = args->window;
	self->was_mouse_pressed = FALSE;
	self->is_active = FALSE;
	self->is_hovered = FALSE;
	if (self->super.module.has_error)
	{
		destroy_checkbox_entity(self);
		return (throw_result_str("init_checkbox_entity()",
			"failed to create new checkbox entity"));
	}
	return (OK);
}
