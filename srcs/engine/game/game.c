/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:23:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:00:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_constructor	game(const char *const name, const t_usize window_size)
{
	static t_game_args	args;

	args.name = name;
	args.window_size = window_size;
	return (ft_constructor(start_game, stop_game, sizeof(t_game), &args));
}
