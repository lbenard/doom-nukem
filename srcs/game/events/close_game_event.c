/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:15:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:13:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/events/events.h"
#include "engine/error.h"
#include "engine/input.h"

static void		close_game_event(t_game *game, SDL_Event *event)
{
	if (input_get(&game_singleton()->input,
			input_get_id(&game_singleton()->input, "Quit")) > 0.0f
			|| event->type == SDL_QUIT)
		window_close(&game->window);
}

t_callback_node	*new_close_game_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(close_game_event, NULL)))
	{
		return (throw_error_str("new_close_game_event()",
			"failed to create new close game event"));
	}
	return (node);
}
