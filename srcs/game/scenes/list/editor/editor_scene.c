/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:31:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 17:58:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

t_constructor	editor_scene(const t_usize window_size)
{
	static t_editor_scene_args	args;

	args.window_size = window_size;
	return (ft_constructor(init_editor_scene,
		destroy_editor_scene,
		sizeof(t_editor_scene),
		&args));
}