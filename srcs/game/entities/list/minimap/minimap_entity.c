/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:27:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"

t_hmodule_factory	minimap_entity(const t_raycasting *renderer,
							const t_usize max_size)
{
	static t_minimap_entity_args	args;

	args.renderer = renderer;
	args.max_size = max_size;
	return (ft_hmodule_factory(ft_hmodule_descriptor(
		(t_new_fn)new_minimap_entity, free_minimap_entity), &args));
}
