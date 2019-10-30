/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_focused.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:25:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:16:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_bool	window_is_focused(const t_window *const self)
{
	return (sfRenderWindow_hasFocus(self->window));
}
