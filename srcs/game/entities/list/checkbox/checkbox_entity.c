/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_entity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:55:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/14 16:59:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

t_constructor	checkbox_entity(const char *const normal_path,
					const char *const hover_path,
					const char *const checked_path,
					const t_window *const window)
{
	static t_checkbox_entity_args	args;

	args.normal_texture_path = normal_path;
	args.hover_texture_path = hover_path;
	args.checked_texture_path = checked_path;
	args.window = window;
	return (ft_constructor(
		init_checkbox_entity,
		destroy_checkbox_entity,
		sizeof(t_checkbox_entity),
		&args
	));
}