/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:32:34 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 13:35:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/benchmark_scene.h"

t_hmodule_factory	benchmark_scene(const size_t entities_number,
						t_window *const window)
{
	static t_benchmark_scene_args	args;

	args.entities_number = entities_number;
	args.window = window;
	return (ft_hmodule_factory(
		ft_hmodule_descriptor(
			(t_new_fn)new_benchmark_scene,
			free_benchmark_scene),
		&args));
}