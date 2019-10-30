/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:31:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"

t_smodule_factory	cursor(const t_usize size, const t_rgba fill_color)
{
	static t_cursor_args	args;

	args.size = size;
	args.fill_color = fill_color;
	return (ft_smodule_factory(ft_smodule_descriptor(init_cursor,
		destroy_cursor), &args));
}
