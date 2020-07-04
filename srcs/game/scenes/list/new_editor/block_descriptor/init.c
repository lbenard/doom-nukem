/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:05:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/03 16:24:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_block_descriptor.h"
#include "engine/error.h"

t_result	init_editor_block_descriptor(t_editor_block_descriptor *const self,
				t_editor_block_descriptor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->texture,
		frame_from_file(args->texture_path));
	self->id = args->id;
	self->name = args->name;
	self->path = args->texture_path;
	if (self->module.has_error)
	{
		destroy_editor_block_descriptor(self);
		return (throw_result_str("init_editor_block_descriptor()",
			"failed to init editor block"));
	}
	return (OK);
}
