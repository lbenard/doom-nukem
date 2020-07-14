/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:11:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:06:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_constructor	window(const char *const name,
					const t_usize size,
					const t_bool fullscreen)
{
	static t_window_args	args;

	args.name = name;
	args.size = size;
	args.fullscreen = fullscreen;
	return (ft_constructor(init_window,
		destroy_window,
		sizeof(t_window),
		&args));
}
