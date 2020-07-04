/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:21:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/03 19:23:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"

t_constructor	menu_scene(const t_window *const window, const char *path)
{
	static t_menu_scene_args	args;

	args.window = window;
	args.path = path;
	return (ft_constructor(init_menu_scene,
		destroy_menu_scene,
		sizeof(t_menu_scene),
		&args));
}
