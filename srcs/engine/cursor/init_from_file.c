/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:36:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"
#include "ft/mem.h"

t_result	init_cursor_from_file(t_cursor *const self,
				const t_cursor_args *const args)
{
	init_module(&self->module);
	module_add_smodule(&self->module, frame_from_file(args->path),
		&self->cursor);
	self->is_visible = TRUE;
	if (self->module.has_error)
	{
		destroy_cursor(self);
		return (throw_result_str("init_cursor_from_file()",
			"failed while creating cursor module"));
	}
	return (OK);
}
