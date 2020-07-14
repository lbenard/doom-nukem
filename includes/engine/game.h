/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:08:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "containers/module.h"
# include "engine/window.h"
# include "engine/input.h"
# include "engine/scene.h"
# include "engine/entity_index.h"
# include "types.h"
# include "engine/event_handler.h"

/*
** A module that represent the game instance, manages scenes and events
*/
typedef struct	s_game
{
	t_module		module;
	t_window		window;
	t_scene			*scene;
	t_input			input;
	t_entity_index	entity_index;
	t_event_handler	event_handler;
}				t_game;

typedef struct	s_game_args
{
	const char	*name;
	t_usize		window_size;
	t_bool		fullscreen;
}				t_game_args;

t_constructor	game(const char *const name,
					const t_usize window_size,
					const t_bool fullscreen);

t_game			*game_singleton(void);

t_result		start_game(const t_game_args *const args);

t_result		game_set_scene(t_constructor constructor);
void			game_loop(void);
void			game_close(void);

void			stop_game(void);

#endif
