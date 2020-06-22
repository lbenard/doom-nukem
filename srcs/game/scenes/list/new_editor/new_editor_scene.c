/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_editor_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:31:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 02:09:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"

t_constructor	new_editor_scene(const t_window *const screen)
{
	static t_new_editor_scene_args	args;

	args.screen = screen;
	return (ft_constructor(init_new_editor_scene,
		destroy_new_editor_scene,
		sizeof(t_new_editor_scene),
		&args));
}