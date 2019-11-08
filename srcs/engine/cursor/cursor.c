/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:31:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:48:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"

t_constructor	cursor(const t_usize size, const t_rgba fill_color)
{
	static t_cursor_args	args;

	args.size = size;
	args.fill_color = fill_color;
	return (ft_constructor(init_cursor,
		destroy_cursor,
		sizeof(t_cursor),
		&args));
}
