/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:26:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 20:15:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_constructor	raycasting_scene(t_window *const window, const char *path)
{
	static t_raycasting_scene_args	args;

	args.window = window;
	args.path = path;
	return (ft_constructor(init_raycasting_scene,
		destroy_raycasting_scene,
		sizeof(t_raycasting_scene),
		&args));
}
