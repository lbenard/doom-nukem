/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:14:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 16:15:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"
#include "engine/array.h"
#include "engine/error.h"

t_result	init_raycasting(t_raycasting *const self,
				const t_raycasting_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->columns,
		array(sizeof(t_ray) * args->window_size.x));
	self->map = args->map;
	self->columns_number = args->window_size.x;
	self->pos = ft_vec2f(args->map->spawn.x, args->map->spawn.y);
	self->dir = ft_vec2f(1.0f, 0.0f);
	self->plane = ft_vec2f(0.0f, 0.66f);
	if (self->module.has_error == TRUE)
	{
		destroy_raycasting(self);
		return (throw_result_str("init_raycasting()",
			"failed to init raycasting module"));
	}
	return (OK);
}
