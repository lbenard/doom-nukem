/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview_checkbox_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:49:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 19:52:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"

t_constructor	preview_checkbox_entity(const char *const normal_path,
						const char *const hover_path,
						const char *const checked_path,
						const char *const preview_path,
						const t_window *const window)
{
	static t_preview_checkbox_entity_args	args;

	args.normal_texture_path = normal_path;
	args.hover_texture_path = hover_path;
	args.checked_texture_path = checked_path;
	args.preview_path = preview_path;
	args.window = window;
	return (ft_constructor(init_preview_checkbox_entity,
		destroy_preview_checkbox_entity,
		sizeof(t_preview_checkbox_entity),
		&args));
}