/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:17:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 16:34:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

t_constructor	button_entity(const char *const path,
					const t_window *const window)
{
	static t_button_entity_args	args;

	args.normal_texture_path = path;
	args.window = window;
	return (ft_constructor(init_button_entity,
		destroy_button_entity,
		sizeof(t_button_entity),
		&args));
}
