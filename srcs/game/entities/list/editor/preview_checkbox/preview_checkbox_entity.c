/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_checkbox_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:49:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:23:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"

t_constructor	preview_checkbox_entity(const char *const base_name,
					const t_frame *const preview,
					const t_window *const window)
{
	static t_preview_checkbox_entity_args	args;

	args.base_name = base_name;
	args.preview = preview;
	args.window = window;
	return (ft_constructor(init_preview_checkbox_entity,
		destroy_preview_checkbox_entity,
		sizeof(t_preview_checkbox_entity),
		&args));
}
