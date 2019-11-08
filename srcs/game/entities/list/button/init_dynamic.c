/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dynamic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:59:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/07 18:45:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/button_entity.h"
#include "engine/error.h"

static void	add_modules(t_button_entity *const self,
				const t_button_entity_args *const args)
{
	module_add(&self->super.module, &self->normal_texture,
		frame_from_file(args->normal_texture_path));
	module_add(&self->super.module, &self->hover_texture,
		frame_from_file(args->hover_texture_path));
	module_add(&self->super.module, &self->click_texture,
		frame_from_file(args->click_texture_path));
}

t_result	init_dynamic_button_entity(t_button_entity *const self,
				const t_button_entity_args *const args)
{
	if (init_classic_entity_default(&self->super, button_entity_update) == ERROR)
	{
		return (throw_result_str("init_dynamic_button_entity()",
			"failed to create button entity"));
	}
	add_modules(self, args);
	self->current_texture = &self->normal_texture;
	self->is_dynamic = TRUE;
	self->is_clicked = FALSE;
	self->window = args->window;
	if (self->super.module.has_error)
	{
		destroy_button_entity(self);
		return (throw_result_str("init_dynamic_button_entity()",
			"failed to create new button entity"));
	}
	return (OK);
}
