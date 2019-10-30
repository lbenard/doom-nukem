/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:06:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:01:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/error.h"

t_result	game_set_scene(t_hmodule_factory factory)
{
	t_game	*game;

	game = game_singleton();
	if (game->scene)
	{
		event_handler_remove_sub_handler(&game->event_handler,
			&game->scene->input_manager);
		module_remove_hmodule(&game->module, (void**)&game->scene);
	}
	module_add_hmodule(&game->module, factory, (void**)&game->scene);
	if (game->module.has_error)
	{
		game_close();
		return (throw_result_str("game_set_scene()",
			"failed to set new scene"));
	}
	window_set_name(&game->window, game->scene->name.str);
	event_handler_add_sub_handler(&game->event_handler,
		&game->scene->input_manager);
	return (OK);
}
