/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:26:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:44:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	window_set_name(t_window *const self, const char *const name)
{
	char	*name_dup;

	if (!(name_dup = ft_strnew(ft_strlen(name)
		+ ft_strlen(self->base_name) + 3)))
		throw_result_str("window_set_name()",
			"failed while duplicating window's name");
	ft_strcat(name_dup, self->base_name);
	ft_strcat(name_dup, " - ");
	ft_strcat(name_dup, name);
	sfRenderWindow_setTitle(self->window, name_dup);
	free((char*)self->name.str);
	self->name.str = name_dup;
	return (OK);
}
