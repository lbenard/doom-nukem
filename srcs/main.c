/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/28 17:42:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "engine/error.h"
#include "engine/controller.h"
#include "engine/game.h"
#include "engine/lookup_table.h"
#include "engine/delta.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/benchmark_scene.h"
#include "game/events/events.h"

void	register_inputs(t_game *const game)
{
	input_register(&game->input, "Forward");
	int forward = input_get_id(&game->input, "Forward");
	input_attach(&game->input, forward, ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&game->input, forward, ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&game->input, forward,
		ft_stick_event(0, XBOX_LSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));


	input_register(&game->input, "Backward");
	int backward = input_get_id(&game->input, "Backward");
	input_attach(&game->input, backward, ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&game->input, backward, ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&game->input, backward,
		ft_stick_event(0, XBOX_LSTICK_Y, 20.0f, STICK_POSITIVE));


	input_register(&game->input, "Left");
	int left = input_get_id(&game->input, "Left");
	input_attach(&game->input, left, ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&game->input, left,
		ft_stick_event(0, XBOX_LSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));


	input_register(&game->input, "Right");
	int right = input_get_id(&game->input, "Right");
	input_attach(&game->input, right, ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&game->input, right,
		ft_stick_event(0, XBOX_LSTICK_X, 20.0f, STICK_POSITIVE));
	
	input_register(&game->input, "Sprint");
	int	sprint = input_get_id(&game->input, "Sprint");
	input_attach(&game->input, sprint, ft_key_event(sfKeyLShift, KEY_HOLD));
	input_attach(&game->input, sprint,
		ft_button_event(0, XBOX_A, INPUT_NO_FLAG));

	input_register(&game->input, "Quit");
	int	quit = input_get_id(&game->input, "Quit");
	input_attach(&game->input, quit, ft_key_event(sfKeyEscape, 0));
	input_attach(&game->input, quit, ft_button_event(0, XBOX_START, 0));

	// input_register(&game->input, "Pause");
	// input_attach(&game->input,
	// 	input_get_id(&game->input, "Pause"),
	// 	ft_button_event(0, XBOX_START));
	// input_attach(&game->input,
	// 	input_get_id(&game->input, "Pause"),
	// 	ft_key_event(sfKeyEscape, )
	// input_register(&game->input, "Backward");
	// input_register(&game->input, "Left");
	// input_register(&game->input, "Right");
	// input_register(&game->input, "TurnLeft");
	// input_register(&game->input, "TurnRight");

	// input_get(&game->input, forward);
}

#include <math.h>
#include <stdio.h>

int	main(void)
{
	t_module	main;
	t_game		*game;
	t_frame		m_bg;
	t_frame		m_fg;
	double		start_time;

	init_module(&main);
	module_add(&main, &m_bg,
		frame(ft_usize(1200, 600), ft_rgba(0, 0, 255, 255)));
	module_add(&main, &m_fg,
		frame_from_file("resources/buttons/start-game.png"));
	printf("pixel: %d %d %d %d\n",
		((t_rgba*)m_fg.frame.array)->c.r,
		((t_rgba*)m_fg.frame.array)->c.g,
		((t_rgba*)m_fg.frame.array)->c.b,
		((t_rgba*)m_fg.frame.array)->c.a);
	start_game(&(t_game_args){"layer test", ft_usize(1200, 600)});
	game = game_singleton();
	register_inputs(game);
	event_handler_add_callback(&game->event_handler, new_close_game_event());
	start_time = get_wall_time();
	while (window_is_running(&game->window))
	{
		frame_fill(&game->window.frame, ft_rgba(0, 0, 0, 255));
		frame_layer_opaque(&game->window.frame, &m_bg, ft_isize(0, 0));
		frame_layer_transform(
			&game->window.frame,
			&m_fg,
			ft_frame_transform(
				ft_vec2f(
					.5f + ((cos(get_wall_time() - start_time)) * .5f),
					.5f + ((sin(get_wall_time() - start_time)) * .5f)),
				ft_isize(1200 / 2, 600 / 2),
				ft_vec2f(
					8.0f,// + ((cos(get_wall_time() - start_time)) * 8.0f),
					8.0f),
				COLOR_OPAQUE),
			blend_add);
		// frame_layer_transform(&game->window.frame, &m_fg,
		// 	ft_frame_transform(ft_vec2f(0.5f, 0.5f),
		// 		ft_isize(1200 / 2 + (int)((cos(get_wall_time() - start_time)) * 200.0f),
		// 			600 / 2 + (int)((sin(get_wall_time() - start_time)) * 200.0f)),
		// 		ft_vec2f(3.0f + (cos(get_wall_time() - start_time)) * 3.0f,
		// 			3.0f + (sin(get_wall_time() - start_time)) * 3.0f),
		// 		255),
		// 		// (int)((cos(get_wall_time() - start_time) + 1.0f) * 127.0f)),
		// 	blend_add);
		game_loop();
	}
	destroy_module(&main);

	return (0);
}

// int	main(void)
// {
// 	t_game	*game;
	
// 	game = game_singleton();
// 	// if (start_game(&(t_game_args){"Doom Nukem", ft_usize(1200, 600)}) == ERROR)
// 	if (start_game(&(t_game_args){"Doom Nukem", ft_usize(640, 480)}) == ERROR)
// 		return (!throw_error_str("main()", "failed to start game"));
// 	register_inputs(game);
// 	// game_set_scene(raycasting_scene(&game->window));
// 	game_set_scene(menu_scene(&game->window));
// 	if (!event_handler_add_callback(&game->event_handler,
// 		new_close_game_event(NULL)))
// 	{
// 		stop_game();
// 		return (!throw_error_str("main()", "failed to add exit callback"));
// 	}
// 	if (game->module.has_error)
// 	{
// 		stop_game();
// 		return (!throw_error_str("main()", "failed to init game"));
// 	}
// 	while (window_is_running(&game->window))
// 		game_loop();
// 	stop_game();
// 	return (0);
// }
