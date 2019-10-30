/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:23:42 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:16:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_bool	window_is_running(const t_window *const self)
{
	return (sfRenderWindow_isOpen(self->window));
}
