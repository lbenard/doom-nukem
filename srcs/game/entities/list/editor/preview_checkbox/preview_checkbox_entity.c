/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_checkbox_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:49:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:28:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"

t_constructor	preview_checkbox_entity(const char *const base_name,
					const char *const preview_path,
					const t_window *const window)
{
	static t_preview_checkbox_entity_args	args;

	args.base_name = base_name;
	args.preview_path = preview_path;
	args.window = window;
	return (ft_constructor(init_preview_checkbox_entity,
		destroy_preview_checkbox_entity,
		sizeof(t_preview_checkbox_entity),
		&args));
}