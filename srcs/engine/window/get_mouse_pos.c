/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 03:58:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 18:18:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "engine/window.h"

t_isize	window_get_mouse_pos(const t_window *const self)
{
	t_vec2i	pos;

	(void)self;
	SDL_GetMouseState(&pos.x, &pos.y);
	return (ft_isize(pos.x, pos.y));
}
