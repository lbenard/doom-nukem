/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:07:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:27:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "engine/delta.h"
#include "ft/io.h"

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
	set_last_delta(spf);
	last_time = get_wall_time();
	game->has_scene_changed = FALSE;
}

void		game_loop(void)
{
	t_game		*game;
	double		last_time;
	SDL_Event	event;

	game = game_singleton();
	last_time = get_wall_time();
	input_update(&game->input);
	while (SDL_PollEvent(&event))
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
