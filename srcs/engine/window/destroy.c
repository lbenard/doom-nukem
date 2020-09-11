/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:27:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 07:39:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/window.h"

void	destroy_window(t_window *const self)
{
	destroy_module(&self->module);
	SDL_DestroyWindow(self->window);
}
