/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:27:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 20:21:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "engine/error.h"

t_result	init_input(t_input *const self)
{
	init_module(&self->module);
	module_add(&self->module, &self->handler, event_handler(self));
	module_add(&self->module, &self->table, vector());
	module_add(&self->module, &self->events, vector());
	if (!self->module.has_error)
		event_handler_add_callback(&self->handler, new_event_update_event());
	if (self->module.has_error)
	{
		destroy_input(self);
		return (throw_result_str("init_input()",
			"failed to init input module"));
	}
	return (OK);
}
