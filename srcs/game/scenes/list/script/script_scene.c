/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 00:47:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/29 16:38:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/script_scene.h"

t_constructor	script_scene(t_window *const window,
					const char *path)
{
	static t_script_scene_args	args;

	args.window = window;
	args.path = path;
	return (ft_constructor(init_script_scene,
		destroy_script_scene,
		sizeof(t_script_scene),
		&args));
}
