/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:32:34 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:35:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/benchmark_scene.h"

t_constructor	benchmark_scene(const size_t entities_number,
					t_window *const window)
{
	static t_benchmark_scene_args	args;

	args.entities_number = entities_number;
	args.window = window;
	return (ft_constructor(init_benchmark_scene,
		destroy_benchmark_scene,
		sizeof(t_benchmark_scene),
		&args));
}