/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_from_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:31:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:49:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"

t_constructor	cursor_from_file(const char *const path)
{
	static t_cursor_args	args;

	args.path = path;
	return (ft_constructor(init_cursor_from_file,
		destroy_cursor,
		sizeof(t_cursor),
		&args));
}
