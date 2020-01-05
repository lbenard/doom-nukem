/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 03:58:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 03:59:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_isize	window_get_mouse_pos(const t_window *const self)
{
	sfVector2i	pos;

	pos = sfMouse_getPositionRenderWindow(self->window);
	return (ft_isize(pos.x, pos.y));
}