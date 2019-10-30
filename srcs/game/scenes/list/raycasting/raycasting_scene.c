/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:26:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_hmodule_factory	raycasting_scene(const t_window *const window)
{
	static t_raycasting_scene_args	args;

	args.window = window;
	return (ft_hmodule_factory(ft_hmodule_descriptor(
		(t_new_fn)new_raycasting_scene, free_raycasting_scene), &args));
}
