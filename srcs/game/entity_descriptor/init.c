/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:05:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:29:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entity_descriptor.h"
#include "engine/error.h"

t_result	init_entity_descriptor(t_entity_descriptor *const self,
				t_entity_descriptor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->icon,
		frame_from_file(args->icon_path));
	self->name = args->name;
	self->icon_path = args->icon_path;
	self->constructor_fn = args->constructor_fn;
	if (self->module.has_error)
	{
		destroy_entity_descriptor(self);
		return (throw_result_str("init_entity_descriptor()",
			"failed to init editor entity"));
	}
	return (OK);
}
