/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:23:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

t_constructor	game(const char *const name,
					const t_usize window_size,
					const t_bool fullscreen)
{
	static t_game_args	args;

	args.name = name;
	args.window_size = window_size;
	args.fullscreen = fullscreen;
	return (ft_constructor(start_game, stop_game, sizeof(t_game), &args));
}
