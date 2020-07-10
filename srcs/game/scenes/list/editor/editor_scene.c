/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:31:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/03 16:32:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

t_constructor	editor_scene(const t_window *const screen,
					const char *const path)
{
	static t_editor_scene_args	args;

	args.screen = screen;
	args.path = path;
	return (ft_constructor(init_editor_scene,
		destroy_editor_scene,
		sizeof(t_editor_scene),
		&args));
}