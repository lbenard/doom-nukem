/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:45:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:50:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"
#include "ft/mem.h"

t_result	init_cursor(t_cursor *const self, const t_cursor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->cursor,
		frame(args->size, args->fill_color));
	self->is_visible = TRUE;
	if (self->module.has_error)
	{
		destroy_cursor(self);
		return (throw_result_str("init_cursor()",
			"failed while creating cursor module"));
	}
	return (OK);
}
