/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:22:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 17:26:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/ascii_font.h"

t_result	init_ascii_font(t_ascii_font *const self,
				const t_ascii_font_args *const args)
{
	init_module(&self->module);
	self->path = args->path;
	module_add(&self->module, &self->raster, frame_from_file(self->path));
	if (self->module.has_error)
	{
		destroy_ascii_font(self);
		return (throw_result_str("init_ascii_font()",
			"failed to init new ascii font"));
	}
	return (OK);
}
