/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:13:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:25:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_game_args	*game_args(const char *name, t_usize window_size)
{
	static t_game_args	args;

	args.name = name;
	args.window_size = window_size;
	return (&args);
}
