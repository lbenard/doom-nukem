/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:32:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:33:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/minimap_entity.h"
#include "engine/error.h"

static t_usize		minimap_size(const t_usize map_size, const t_usize max_size)
{
	float				x_ratio;
	float				y_ratio;

	x_ratio = (float)map_size.x / max_size.x;
	y_ratio = (float)map_size.y / max_size.y;
	if (x_ratio > y_ratio)
		return (ft_usize(map_size.x / x_ratio, map_size.y / x_ratio));
	else
		return (ft_usize(map_size.x / y_ratio, map_size.y / y_ratio));
}

t_result	init_minimap_entity(t_minimap_entity *const self,
				const t_minimap_entity_args *const args)
{
	init_classic_entity_default(&self->super, minimap_entity_update);
	self->size = minimap_size(args->renderer->map->size, args->max_size);
	module_add(&self->super.module, &self->minimap,
		frame(self->size, ft_rgba(255, 255, 255, 64)));
	self->raycasting_ref = args->renderer;
	if (self->super.module.has_error)
	{
		destroy_minimap_entity(self);
		return (throw_result_str("init_minimap_entity()",
			"failed while creating minimap entity"));
	}
	return (OK);
}
