/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 21:07:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "engine/error.h"
#include "engine/controller.h"
#include "engine/game.h"
#include "engine/lookup_table.h"
#include "engine/delta.h"
#include "engine/ascii_font.h"
#include "engine/text.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/new_editor_scene.h"
#include "game/scenes/noise_test_scene.h"
// #include "game/scenes/sector_scene.h"
#include "game/scenes/raycasting_scene.h"
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

	input_register(&game->input, "CameraRight");
	int camera_right = input_get_id(&game->input, "CameraRight");
	input_attach(&game->input, camera_right, ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&game->input, camera_right,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_POSITIVE));

	input_register(&game->input, "CameraLeft");
	int camera_left = input_get_id(&game->input, "CameraLeft");
	input_attach(&game->input, camera_left, ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&game->input, camera_left,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	input_register(&game->input, "CameraUp");
	int camera_up = input_get_id(&game->input, "CameraUp");
	input_attach(&game->input, camera_up, ft_key_event(sfKeyPageUp, KEY_HOLD));
	input_attach(&game->input, camera_up,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));
	
	input_register(&game->input, "CameraDown");
	int camera_down = input_get_id(&game->input, "CameraDown");
	input_attach(&game->input, camera_down, ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
	input_attach(&game->input, camera_down,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_POSITIVE | INVERT_INPUT));
	
	input_register(&game->input, "EditorCameraUp");
	int editor_camera_up = input_get_id(&game->input, "EditorCameraUp");
	input_attach(&game->input, editor_camera_up, ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&game->input, editor_camera_up, ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&game->input, editor_camera_up,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	input_register(&game->input, "EditorCameraRight");
	int editor_camera_right = input_get_id(&game->input, "EditorCameraRight");
	input_attach(&game->input, editor_camera_right, ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&game->input, editor_camera_right, ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&game->input, editor_camera_right,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_POSITIVE));

	input_register(&game->input, "EditorCameraDown");
	int editor_camera_down = input_get_id(&game->input, "EditorCameraDown");
	input_attach(&game->input, editor_camera_down, ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&game->input, editor_camera_down, ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&game->input, editor_camera_down,
		ft_stick_event(0, XBOX_RSTICK_Y, 20.0f, STICK_POSITIVE));

	input_register(&game->input, "EditorCameraLeft");
	int editor_camera_left = input_get_id(&game->input, "EditorCameraLeft");
	input_attach(&game->input, editor_camera_left, ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&game->input, editor_camera_left, ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&game->input, editor_camera_left,
		ft_stick_event(0, XBOX_RSTICK_X, 20.0f, STICK_NEGATIVE | INVERT_INPUT));

	input_register(&game->input, "EditorCameraDezoom");
	int editor_camera_dezoom = input_get_id(&game->input, "EditorCameraDezoom");
	input_attach(&game->input, editor_camera_dezoom,
		ft_key_event(sfKeySubtract, KEY_HOLD | INVERT_INPUT));
	input_attach(&game->input, editor_camera_dezoom,
		ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
	
	input_register(&game->input, "EditorCameraZoom");
	int editor_camera_zoom = input_get_id(&game->input, "EditorCameraZoom");
	input_attach(&game->input, editor_camera_zoom, ft_key_event(sfKeyAdd, KEY_HOLD));
	input_attach(&game->input, editor_camera_zoom, ft_key_event(sfKeyPageUp, KEY_HOLD));
	
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
	input_register(&game->input, "TurnLeft");
	int	turn_left = input_get_id(&game->input, "TurnLeft");
	input_attach(&game->input, turn_left, ft_key_event(sfKeyLeft, KEY_HOLD));
	input_register(&game->input, "TurnRight");
	int	turn_right = input_get_id(&game->input, "TurnRight");
	input_attach(&game->input, turn_right, ft_key_event(sfKeyRight, KEY_HOLD));

	// input_get(&game->input, forward);
}

int	main(void)
{
	t_game	*game;
	
	game = game_singleton();
	// if (start_game(&(t_game_args){"Doom Nukem", ft_usize(1280, 720)}) == ERROR)
	if (start_game(&(t_game_args){"Doom Nukem", ft_usize(1200, 600)}) == ERROR)
	// if (start_game(&(t_game_args){"Doom Nukem", ft_usize(640, 480)}) == ERROR)
		return (!throw_error_str("main()", "failed to start game"));
	register_inputs(game);
	// game_set_scene(sector_scene());
	// game_set_scene(menu_scene(&game->window));
	// game_set_scene(noise_test_scene());
	game_set_scene(new_editor_scene(&game->window));
	// game_set_scene(raycasting_scene(&game->window));
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
// 	module_add(&module, &m_text, text("haxorville.png", ft_usize(1280, 720)));
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
