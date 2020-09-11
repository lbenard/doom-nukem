/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:23:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 18:07:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_bool	window_is_running(const t_window *const self)
{
	return (self->is_opened);
}
