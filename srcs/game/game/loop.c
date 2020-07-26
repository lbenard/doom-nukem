/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:07:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 19:17:56 by lbenard          ###   ########.fr       */
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
	// printf("average: %f\n", total_fps / total_frames);
}

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
	input_update(&game->input);
	if (game->scene)
		game->scene->update_fn(game->scene);
	if (game->module.has_error)
	{
		game_close();
		return ;
	}
	if (window_is_focused(&game->window))
	{
		if (game->scene && !game->has_scene_changed)
			game->scene->render_fn(game->scene, &game->window.frame);
		window_update(&game->window);
	}
	spf = get_wall_time() - last_time;
	fps_average(spf);
	if (spf > MAX_DELTA)
	{
		// ft_putstr("cpu just had a stroke (got ");
		// ft_putnbr(1.0f / spf);
		// ft_putstr("fps, expected at least ");
		// ft_putnbr(1.0f / MAX_DELTA);
		// ft_putstr("fps)\n");
	}
	set_last_delta(spf);
	last_time = get_wall_time();
	game->has_scene_changed = FALSE;
}
