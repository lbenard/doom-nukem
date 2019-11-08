/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:26:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:41:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_constructor	raycasting_scene(const t_window *const window)
{
	static t_raycasting_scene_args	args;

	args.window = window;
	return (ft_constructor(init_raycasting_scene,
		destroy_raycasting_scene,
		sizeof(t_raycasting_scene),
		&args));
}
