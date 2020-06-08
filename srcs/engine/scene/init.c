/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:22:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:59:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_scene(t_scene *const self,
				const char *const name,
				void (*update_fn)(),
				void (*render_fn)())
{
	init_module(&self->module);
	module_add(&self->module, &self->name, string(name));
	module_add(&self->module, &self->entities, entity_list());
	module_add(&self->module, &self->input_manager, event_handler(self));
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
