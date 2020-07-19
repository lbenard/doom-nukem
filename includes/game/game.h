/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 19:03:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "containers/module.h"
# include "engine/window.h"
# include "engine/input.h"
# include "engine/scene.h"
# include "engine/entity_index.h"
# include "engine/event_handler.h"
# include "game/block_descriptor.h"
# include "game/entity_descriptor.h"
# include "types.h"

/*
** A module that represent the game instance, manages scenes and events
*/
typedef struct	s_game
{
	t_module				module;
	t_window				window;
	t_scene					*scene;
	t_input					input;
	t_entity_index			entity_index;
	t_event_handler			event_handler;
	struct s_blocks
	{
		t_block_descriptor	blue_ice;
		t_block_descriptor	white_wool;
		t_block_descriptor	acacia_log;
	}						blocks_list;
	struct s_entities
	{
		t_entity_descriptor	onepunchman;
		// t_entity_descriptor	white_wool;
		// t_entity_descriptor	acacia_log;
	}						entities_list;
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
void			init_block_descriptors(t_game *const self);
void			init_entity_descriptors(t_game *const self);

t_result		game_set_scene(t_constructor constructor);
void			game_loop(void);
void			game_close(void);

void			stop_game(void);

#endif
