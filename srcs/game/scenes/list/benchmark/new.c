/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:12:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 19:49:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/benchmark_scene.h"
#include "game/entities/player_entity.h"
#include "engine/error.h"

static void			add_entities(t_benchmark_scene *const self,
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

t_benchmark_scene	*new_benchmark_scene(
						const t_benchmark_scene_args *const args)
{
	t_benchmark_scene	*ret;

	if (!(ret = (t_benchmark_scene*)malloc(sizeof(t_benchmark_scene))))
	{
		return (throw_error_str("new_benchmark_scene()",
			"failed to allocate benchmark scene"));
	}
	if (init_scene(&ret->super, "Benchmarking scene",
		benchmark_scene_update, benchmark_scene_render) == ERROR)
	{
		free(ret);
		return (throw_error_str("new_benchmark_scene()",
			"failed to init scene"));
	}
	module_add_smodule(&ret->super.module, map("maps/maze_test.dn"), &ret->map);
	if (ret->super.module.has_error == FALSE)
		add_entities(ret, args);
	if (ret->super.module.has_error)
	{
		free_benchmark_scene(ret);
		return (throw_error_str("new_benchmark_scene()",
			"failed while creating benchmarking scene module"));
	}
	return (ret);
}
