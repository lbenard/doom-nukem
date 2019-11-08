/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:21:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:37:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"

t_constructor	menu_scene(const t_window *const window)
{
	static t_menu_scene_args	args;

	args.window = window;
	return (ft_constructor(init_menu_scene,
		destroy_menu_scene,
		sizeof(t_menu_scene),
		&args));
}
