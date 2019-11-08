/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:12:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:36:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/benchmark_scene.h"
#include "game/entities/player_entity.h"
#include "engine/error.h"

static void	add_entities(t_benchmark_scene *const self,
				const t_benchmark_scene_args *const args)
{
	size_t	i;

	i = 0;
	while (i < args->entities_number)
	{
		entity_list_add_entity(&self->super.entities,
			player_entity(&self->map));
		i++;
	}
}

t_result	init_benchmark_scene(t_benchmark_scene *const self,
				const t_benchmark_scene_args *const args)
{
	if (init_scene(&self->super, "Benchmarking scene",
		benchmark_scene_update, benchmark_scene_render) == ERROR)
	{
		return (throw_result_str("init_benchmark_scene()",
			"failed to init scene"));
	}
	module_add(&self->super.module, &self->map, map("maps/maze_test.dn"));
	if (self->super.module.has_error == FALSE)
		add_entities(self, args);
	if (self->super.module.has_error)
	{
		destroy_benchmark_scene(self);
		return (throw_result_str("init_benchmark_scene()",
			"failed while creating benchmarking scene module"));
	}
	return (OK);
}
