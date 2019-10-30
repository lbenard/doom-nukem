/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:07:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:25:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/delta.h"

#include <stdio.h>

void	game_loop(void)
{
	t_game	*game;
	double	last_time;
	sfEvent	event;
	double	spf;

	game = game_singleton();
	last_time = get_wall_time();
	while (sfRenderWindow_pollEvent(game->window.window, &event))
		event_handler_call(&game->event_handler, &event);
	if (game->scene)
		game->scene->update_fn(game->scene);
	if (game->module.has_error)
	{
		game_close();
		return ;
	}
	if (window_is_focused(&game->window))
	{
		if (game->scene)
			game->scene->render_fn(game->scene, &game->window.frame);
		window_update(&game->window);
	}
	spf = get_wall_time() - last_time;
	// printf("fps: %f\n", 1.0f / spf);
	set_last_delta(spf);
	last_time = get_wall_time();
}
