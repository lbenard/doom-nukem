/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:05:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 20:28:14 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/block_descriptor.h"
#include "engine/error.h"

t_result	init_block_descriptor(t_block_descriptor *const self,
				t_block_descriptor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->texture,
		frame_from_file(args->texture_path));
	self->id = args->id;
	self->name = args->name;
	self->path = args->texture_path;
	if (self->module.has_error)
	{
		destroy_block_descriptor(self);
		return (throw_result_str("init_block_descriptor()",
			"failed to init editor block"));
	}
	return (OK);
}
