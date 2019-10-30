/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:22:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 00:51:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "engine/error.h"
#include "engine/string.h"
#include "ft/str.h"

t_result	init_scene(t_scene *const self,
				const char *const name,
				void (*update_fn)(),
				void (*render_fn)())
{
	init_module(&self->module);
	module_add_smodule(&self->module, string(name), &self->name);
	module_add_smodule(&self->module, entity_list(), &self->entities);
	module_add_smodule(&self->module, event_handler(self),
		&self->input_manager);
	self->update_fn = update_fn;
	self->render_fn = render_fn;
	if (self->module.has_error)
	{
		destroy_scene(self);
		return (throw_result_str("init_scene()",
			"failed while creating new scene"));
	}
	return (OK);
}
