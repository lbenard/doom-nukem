/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_focused.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:25:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 18:11:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_bool	window_is_focused(const t_window *const self)
{
	return (SDL_GetWindowFlags(self->window) | SDL_WINDOW_MOUSE_FOCUS);
}
