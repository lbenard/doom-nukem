/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:04:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/error.h"

t_result	start_game(const t_game_args *const args)
{
	t_game	*game;

	game = game_singleton();
	init_module(&game->module);
	module_add_smodule(&game->module,
		window(args->name, args->window_size), &game->window);
	module_add_smodule(&game->module, event_handler(game),
		&game->event_handler);
	game->scene = NULL;
	if (game->module.has_error)
	{
		stop_game();
		return (throw_result_str("start_game()",
			"error while creating game module"));
	}
	return (OK);
}
