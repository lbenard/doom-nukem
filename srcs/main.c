/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 10:56:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/game.h"
#include "game/scenes/menu_scene.h"
#include "game/events/events.h"

int	main(int ac, char **av)
{
	t_game	*game;

	(void)av;
	if (ac != 2)
		return (!throw_error_str("main()", "a map path must be given"));
	game = game_singleton();
	if (!start_game(&(t_game_args){PROGRAM_NAME, ft_usize(1280, 720), FALSE}))
		return (!throw_error_str("main()", "failed to start game"));
	game_set_scene(menu_scene(&game->window, av[1]));
	if (!event_handler_add_callback(&game->event_handler,
		new_close_game_event()))
	{
		stop_game();
		return (!throw_error_str("main()", "failed to add exit callback"));
	}
	if (game->module.has_error)
	{
		stop_game();
		return (!throw_error_str("main()", "failed to init game"));
	}
	while (window_is_running(&game->window))
		game_loop();
	stop_game();
	return (0);
}
