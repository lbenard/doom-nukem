/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:09:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 01:56:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/game.h"
#include "engine/scene.h"

void	stop_game(void)
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
	destroy_module(&game_singleton()->module);
}
