/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:04:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/07 20:10:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"

void	cursor_set_pos(t_cursor *const self,
			const sfRenderWindow *const window,
			const t_isize pos)
{
	sfVector2i	pos_cursor;

	(void)self;
	pos_cursor.x = pos.x;
	pos_cursor.y = pos.y;
	sfMouse_setPositionRenderWindow(pos_cursor, window);
}
