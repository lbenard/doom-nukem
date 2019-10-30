/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:27:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:38:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/window.h"

void	destroy_window(t_window *const self)
{
	destroy_module(&self->module);
	sfRenderWindow_destroy(self->window);
}
