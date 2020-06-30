/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:37:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"
#include "engine/error.h"

t_result	init_block_checkbox_entity(t_block_checkbox_entity *const self,
				const t_block_checkbox_entity_args *const args)
{
	if (static_module_create(self, preview_checkbox_entity(args->base_name,
		args->block_path, args->window)) == ERROR)
	{
		return (throw_result_str("init_block_checkbox_entity()",
			"failed to create parent object"));
	}
	module_add(&self->super.super.super.module, &self->block,
		frame_from_file(args->block_path));
	if (self->super.super.super.module.has_error)
	{
		destroy_block_checkbox_entity(self);
		return (throw_result_str("init_block_checkbox_entity()",
			"failed to create block checkbox entity"));
	}
	return (OK);
}
