/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:07:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 20:32:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "engine/delta.h"
#include "ft/io.h"

#include <stdio.h>

static void	fps_average(double spf)
{
	static double	total_fps = 0;
	static size_t	total_frames = 0.0f;

	total_fps += 1.0f / spf;
	total_frames++;
}

static void	game_loop2(t_game *game, double last_time)
{
	double	spf;

	if (window_is_focused(&game->window))
	{
		if (game->scene && !game->has_scene_changed)
			game->scene->render_fn(game->scene, &game->window.frame);
		window_update(&game->window);
	}
	spf = get_wall_time() - last_time;
	fps_average(spf);
	set_last_delta(spf);
	last_time = get_wall_time();
	game->has_scene_changed = FALSE;
}

void		game_loop(void)
{
	t_game	*game;
	double	last_time;
	sfEvent	event;

	game = game_singleton();
	last_time = get_wall_time();
	input_update(&game->input);
	while (sfRenderWindow_pollEvent(game->window.window, &event))
		event_handler_call(&game->event_handler, &event);
	if (game->scene)
		game->scene->update_fn(game->scene);
	if (game->module.has_error)
	{
		game_close();
		return ;
	}
	game_loop2(game, last_time);
}
