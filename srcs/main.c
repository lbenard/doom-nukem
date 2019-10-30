/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 16:56:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "engine/error.h"
#include "engine/game.h"
#include "engine/lookup_table.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/benchmark_scene.h"
#include "game/events/events.h"

// void	register_inputs(t_game *const game)
// {
// 	input_register(&game->input, "Forward");
// 	int forward = input_get_id(&game->input, "Forward");
// 	input_attach(&game->input,
// 		forward,
// 		ft_key_input(sfKeyW, KEY_HOLD));
// 	input_attach(&game->input,
// 		forward,
// 		ft_stick_input(0, XBOX_LSTICK_Y, 15.0f, STICK_NEGATIVE));
// 	input_register(&game->input, "Backward");
// 	int backward = input_get_id(&game->input, "Backward");
// 	input_attach(&game->input,
// 		backward,
// 		ft_key_input(sfKeyS, true));
// 	input_attach(&game->input,
// 		backward,
// 		ft_stick_input(0, XBOX_LSTICK_Y, 15.0f, STICK_POSITIVE));

// 	input_register(&game->input, "Pause");
// 	input_attach(&game->input,
// 		input_get_id(&game->input, "Pause"),
// 		ft_button_input(0, XBOX_START));
// 	input_register(&game->input, "Backward");
// 	input_register(&game->input, "Left");
// 	input_register(&game->input, "Right");
// 	input_register(&game->input, "TurnLeft");
// 	input_register(&game->input, "TurnRight");

// 	input_get(&game->input, forward)
// }

#include "engine/controller.h"
#include <stdio.h>



int	main(void)
{
	while (1)
	{
		sfJoystick_update();
		// printf("%s\n", sfJoystick_getIdentification(0).name);
		printf("%f\n", sfJoystick_getAxisPosition(0, XBOX_LSTICK_Y));
	}
	// t_game	*game;

	// game = game_singleton();
	// if (start_game(game_args("Doom Nukem", ft_usize(640, 480))) == ERROR)
	// 	return (!throw_error_str("main()", "failed to start game"));
	// game_set_scene(menu_scene(&game->window));
	// if (!event_handler_add_callback(&game->event_handler,
	// 	new_close_game_event(NULL)))
	// {
	// 	stop_game();
	// 	return (!throw_error_str("main()", "failed to add exit callback"));
	// }
	// if (game->module.has_error)
	// {
	// 	stop_game();
	// 	return (!throw_error_str("main()", "failed to init game"));
	// }
	// while (window_is_running(&game->window))
	// 	game_loop();
	// stop_game();
	return (0);
}
