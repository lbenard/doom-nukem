/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 02:38:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "engine/error.h"
#include "engine/controller.h"
#include "game/game.h"
#include "engine/lookup_table.h"
#include "engine/delta.h"
#include "engine/ascii_font.h"
#include "engine/text.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/editor_scene.h"
#include "game/scenes/script_scene.h"
#include "game/scenes/raycasting_scene.h"
#include "game/events/events.h"

void	register_inputs(t_game *const game)
{
	int forward = input_register(&game->input, "Forward");
	input_attach(&game->input, forward, ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&game->input, forward, ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&game->input, forward,
		ft_stick_event(0, XBOX_LSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	int backward = input_register(&game->input, "Backward");
	input_attach(&game->input, backward, ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&game->input, backward, ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&game->input, backward,
		ft_stick_event(0, XBOX_LSTICK_Y, 20.0f, STICK_POSITIVE));

	int left = input_register(&game->input, "Left");
	input_attach(&game->input, left, ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&game->input, left,
		ft_stick_event(0, XBOX_LSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	int right = input_register(&game->input, "Right");
	input_attach(&game->input, right, ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&game->input, right,
		ft_stick_event(0, XBOX_LSTICK_X, 20.0f, STICK_POSITIVE));

	int jump = input_register(&game->input, "Jump");
	input_attach(&game->input, jump, ft_key_event(sfKeySpace, KEY_HOLD));
	input_attach(&game->input, jump,
		ft_button_event(0, XBOX_B, 0));

	int crouch = input_register(&game->input, "Crouch");
	input_attach(&game->input, crouch, ft_key_event(sfKeyLControl, KEY_HOLD));
	input_attach(&game->input, crouch,
		ft_button_event(0, XBOX_Y, 0));
	
	int	turn_left = input_register(&game->input, "TurnLeft");
	input_attach(&game->input, turn_left, ft_key_event(sfKeyLeft, KEY_HOLD));

	int	turn_right = input_register(&game->input, "TurnRight");
	input_attach(&game->input, turn_right, ft_key_event(sfKeyRight, KEY_HOLD));

	int	sprint = input_register(&game->input, "Sprint");
	input_attach(&game->input, sprint, ft_key_event(sfKeyLShift, KEY_HOLD));
	input_attach(&game->input, sprint,
		ft_button_event(0, XBOX_A, INPUT_NO_FLAG));

	int	toggle_flight = input_register(&game->input, "ToggleFlight");
	input_attach(&game->input, toggle_flight, ft_key_event(sfKeyF, 0));

	int use = input_register(&game->input, "Use");
	input_attach(&game->input, use, ft_key_event(sfKeyE, KEY_HOLD));
	input_attach(&game->input, use, ft_button_event(0, XBOX_A, 0));

	int shoot = input_register(&game->input, "Shoot");
	input_attach(&game->input, shoot, ft_mouse_event(sfMouseLeft, MOUSE_HOLD));
	input_attach(&game->input, shoot, ft_key_event(sfKeyEnter, KEY_HOLD));
	input_attach(&game->input, shoot,
		ft_stick_event(0, XBOX_RTRIGGER, 20.0f, 0));

	int reload = input_register(&game->input, "Reload");
	input_attach(&game->input, reload, ft_key_event(sfKeyR, 0));
	input_attach(&game->input, reload, ft_button_event(0, XBOX_A, 0));

	int camera_right = input_register(&game->input, "CameraRight");
	input_attach(&game->input, camera_right, ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&game->input, camera_right,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_POSITIVE));

	int camera_left = input_register(&game->input, "CameraLeft");
	input_attach(&game->input, camera_left, ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&game->input, camera_left,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	int camera_up = input_register(&game->input, "CameraUp");
	input_attach(&game->input, camera_up, ft_key_event(sfKeyPageUp, KEY_HOLD));
	input_attach(&game->input, camera_up,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));
	
	int camera_down = input_register(&game->input, "CameraDown");
	input_attach(&game->input, camera_down, ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
	input_attach(&game->input, camera_down,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_POSITIVE | INVERT_INPUT));
	
	int editor_camera_up = input_register(&game->input, "EditorCameraUp");
	input_attach(&game->input, editor_camera_up, ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&game->input, editor_camera_up, ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&game->input, editor_camera_up,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	int editor_camera_right = input_register(&game->input, "EditorCameraRight");
	input_attach(&game->input, editor_camera_right, ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&game->input, editor_camera_right, ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&game->input, editor_camera_right,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_POSITIVE));

	int editor_camera_down = input_register(&game->input, "EditorCameraDown");
	input_attach(&game->input, editor_camera_down, ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&game->input, editor_camera_down, ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&game->input, editor_camera_down,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_POSITIVE));

	int editor_camera_left = input_register(&game->input, "EditorCameraLeft");
	input_attach(&game->input, editor_camera_left, ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&game->input, editor_camera_left, ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&game->input, editor_camera_left,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	int editor_camera_dezoom = input_register(&game->input, "EditorCameraDezoom");
	input_attach(&game->input, editor_camera_dezoom,
		ft_key_event(sfKeySubtract, KEY_HOLD | INVERT_INPUT));
	input_attach(&game->input, editor_camera_dezoom,
		ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
	
	int editor_camera_zoom = input_register(&game->input, "EditorCameraZoom");
	input_attach(&game->input, editor_camera_zoom, ft_key_event(sfKeyAdd, KEY_HOLD));
	input_attach(&game->input, editor_camera_zoom, ft_key_event(sfKeyPageUp, KEY_HOLD));

	int	quit = input_register(&game->input, "Quit");
	input_attach(&game->input, quit, ft_key_event(sfKeyEscape, 0));
	input_attach(&game->input, quit, ft_button_event(0, XBOX_START, 0));

	// input_register(&game->input, "Back");
	// int	quit = input_get_id(&game->input, "Quit");
	// input_attach(&game->input, quit, ft_key_event(sfKeyEscape, 0));
	// input_attach(&game->input, quit, ft_button_event(0, XBOX_START, 0));

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

	// input_get(&game->input, forward);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (!throw_error_str("main()", "a map path must be given"));
	game = game_singleton();
	if (start_game(&(t_game_args){PROGRAM_NAME, ft_usize(1280, 720), TRUENT}) == ERROR)
		return (!throw_error_str("main()", "failed to start game"));
	register_inputs(game);
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

// leak avec un sprite (56 bytes)

// int	main(void)
// {
// 	t_module		main_module;
// 	t_frame			screen;
// 	sfRenderWindow	*window;
// 	sfVideoMode		mode;

// 	init_module(&main_module);
// 	module_add(&main_module, &screen, frame(ft_usize(1280, 720), ft_rgba(0, 0, 0, 255)));
// 	if (main_module.has_error)
// 		return (-1);
// 	mode.width = 1280;
// 	mode.height = 720;
// 	mode.bitsPerPixel = 24;
// 	if (!(window = sfRenderWindow_create(mode, "test", sfClose, NULL)))
// 	{
// 		destroy_module(&main_module);
// 		return (-1);
// 	}
// 	sfRenderWindow_drawSprite(window, screen.sprite.sprite, NULL);
// 	// sfRenderWindow_clear(window, sfRed);
// 	// sfRenderWindow_display(window);
// 	sfRenderWindow_destroy(window);
// 	destroy_module(&main_module);
// 	return (0);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_module		module;
// 	t_game			*game;
// 	t_text			m_text;
// 	t_string		m_string;
// 	// double			wall;

// 	start_game(&(t_game_args){"Test", ft_usize(1280, 720)});
// 	game = game_singleton();
// 	register_inputs(game);
// 	init_module(&module);
// 	module_add(&module, &m_text, text("haxorville.bmp", ft_usize(1280, 720)));
// 	module_add(&module, &m_string, string("these are the signs of warning\n"
// 		"symbols of danger\n"
// 		"some are all too familiar\n"
// 		"this one, signals the most ominous threat of all\n"
// 		"by the time you see it, it may already be too late\n"));
// 	// module_add(&module, &m_string, string("Doom Nukem"));
// 	event_handler_add_callback(&game->event_handler, new_close_game_event());
// 	if (module.has_error)
// 		return (0);
// 	text_set_ref(&m_text, string_as_ref(&m_string));
// 	frame_fill_blend(&m_text.font.raster, ft_rgba(0, 0, 0, 255), blend_colorize);
// 	text_render(&m_text, ft_text_settings(ft_isize(0, 0), 42));
// 	// wall = get_wall_time();
// 	while (window_is_running(&game->window))
// 	{
// 		frame_fill(&game->window.frame, ft_rgba(255, 255, 255, 255));
// 		// frame_layer_transform(&game->window.frame,
// 		// 	&m_font.raster,
// 		// 	ft_frame_transform(
// 		// 		ft_vec2f(0.0f, 0.0f),
// 		// 		ft_isize(0, 0),z
// 		// 		ft_vec2f(1.0f / 10.0f, 1.0f / 10.0f),
// 		// 		COLOR_OPAQUE),
// 		// 	blend_add);
// 		frame_layer_transform(&game->window.frame,
// 			&m_text.target,
// 			ft_frame_transform(
// 				ft_vec2f(0.0f, 0.0f),
// 				ft_isize(10, 10),
// 				ft_vec2f(1.0f, 1.0f),
// 				COLOR_OPAQUE),
// 			blend_add);
// 		game_loop();
// 	}
// 	stop_game();
// 	destroy_module(&module);
// 	return (0);
// }
