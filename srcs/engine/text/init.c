/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:49:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/09 14:10:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"
#include "engine/error.h"

t_result	init_text(t_text *const self, const t_text_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->target,
		frame(args->view_size, ft_rgba(0, 0, 0, 0)));
	module_add(&self->module, &self->font, ascii_font(args->font_path));
	module_add(&self->module, &self->text, string(""));
	if (self->module.has_error)
		return (throw_result_str("init_text", "failed to init new text"));
	return (OK);
}
