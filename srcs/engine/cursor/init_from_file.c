/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:36:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:50:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"
#include "ft/mem.h"

t_result	init_cursor_from_file(t_cursor *const self,
				const t_cursor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->cursor, frame_from_file(args->path));
	self->is_visible = TRUE;
	if (self->module.has_error)
	{
		destroy_cursor(self);
		return (throw_result_str("init_cursor_from_file()",
			"failed while creating cursor module"));
	}
	return (OK);
}
