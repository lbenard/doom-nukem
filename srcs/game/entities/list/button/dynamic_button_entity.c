/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_button_entity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:32:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/07 18:45:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

t_constructor	dynamic_button_entity(const char *const normal_path,
					const char *const hover_path,
					const char *const click_path,
					const t_window *const window)
{
	static t_button_entity_args	args;

	args.normal_texture_path = normal_path;
	args.hover_texture_path = hover_path;
	args.click_texture_path = click_path;
	args.window = window;
	return (ft_constructor(init_dynamic_button_entity,
		destroy_button_entity,
		sizeof(t_button_entity),
		&args));
}
