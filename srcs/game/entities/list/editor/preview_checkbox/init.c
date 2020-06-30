/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:53:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:25:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"
#include "engine/error.h"

t_result	init_preview_checkbox_entity(t_preview_checkbox_entity *const self,
				const t_preview_checkbox_entity_args *const args)
{
	if (static_module_create(&self->super, checkbox_entity_base(
		args->base_name, args->window)) == ERROR)
	{
		return (throw_result_str("init_preview_checkbox_entity()",
			"failed to init parent class"));
	}
	module_add(&self->super.super.module,
		&self->preview,
		frame_from_file(args->preview_path));
	if (self->super.super.module.has_error)
	{
		destroy_preview_checkbox_entity(self);
		return (throw_result_str("init_preview_checkbox_entity()",
			"failed to init preview checkbox entity"));
	}
	return (OK);
}
