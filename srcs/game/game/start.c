/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:04:22 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 19:16:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "engine/error.h"

t_result	start_game(const t_game_args *const args)
{
	t_game	*game;

	game = game_singleton();
	init_module(&game->module);
	module_add(&game->module, &game->window,
		window(args->name, args->window_size, args->fullscreen));
	module_add(&game->module, &game->event_handler, event_handler(game));
	module_add(&game->module, &game->input, input());
	init_block_descriptors(game);
	init_entity_descriptors(game);
	game->scene = NULL;
	game->has_scene_changed = FALSE;
	if (game->module.has_error)
	{
		stop_game();
		return (throw_result_str("start_game()",
			"error while creating game module"));
	}
	return (OK);
}
