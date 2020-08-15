/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:53:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 02:10:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

t_constructor	editor_scene_from_file(const t_usize window_size,
					const char *const path)
{
	static	t_editor_scene_args	args;

	args.window_size = window_size;
	args.path = path;
	return (ft_constructor(
		init_editor_scene_from_file,
		destroy_editor_scene,
		sizeof(t_editor_scene),
		&args));
}
