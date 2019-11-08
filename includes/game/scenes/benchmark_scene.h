/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_scene.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:08:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:34:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_SCENE_H
# define BENCHMARK_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/map.h"

typedef struct	s_benchmark_scene
{
	t_scene	super;
	t_map	map;
}				t_benchmark_scene;

typedef struct	s_benchmark_scene_args
{
	size_t		entities_number;
	t_window	*window;
}				t_benchmark_scene_args;

t_constructor	benchmark_scene(const size_t entities_number,
					t_window *const window);

t_result		init_benchmark_scene(t_benchmark_scene *const self,
					const t_benchmark_scene_args *const args);

void			benchmark_scene_update(t_benchmark_scene *const self);
void			benchmark_scene_render(t_benchmark_scene *const self,
					t_frame *const fb);

void			destroy_benchmark_scene(t_benchmark_scene *const self);

#endif