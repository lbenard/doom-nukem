/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:27:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:30:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"

t_constructor	minimap_entity(const t_raycasting *renderer,
					const t_usize max_size)
{
	static t_minimap_entity_args	args;

	args.renderer = renderer;
	args.max_size = max_size;
	return (ft_constructor(init_minimap_entity,
		destroy_minimap_entity,
		sizeof(t_minimap_entity), &args));
}
