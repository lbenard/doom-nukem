/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:06:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 01:56:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/game.h"
#include "engine/error.h"

t_result	game_set_scene(t_constructor constructor)
{
	t_game	*game;

	game = game_singleton();
	if (game->scene)
	{
		event_handler_remove_sub_handler(&game->event_handler,
			&game->scene->input_manager);
		game->scene_destructor_fn(game->scene);
		free(game->scene);
	}
	game->scene = static_module_allocate(constructor);
	if (!game->scene)
	{
		game_close();
		return (throw_result_str("game_set_scene()",
			"failed to set new scene"));
	}
	game->scene_destructor_fn = constructor.destructor_fn;
	window_set_name(&game->window, game->scene->name.str);
	event_handler_add_sub_handler(&game->event_handler,
		&game->scene->input_manager);
	game->has_scene_changed = TRUE;
	return (OK);
}
