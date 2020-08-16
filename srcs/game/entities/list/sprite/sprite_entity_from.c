/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_entity_from.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:55:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:57:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"

t_constructor	sprite_entity_from(const t_vec3f pos,
					const t_frame *const from,
					t_raycasting_scene *const ctx)
{
	static t_sprite_entity_args	args;

	args.pos = pos;
	args.from = from;
	args.ctx = ctx;
	return (ft_constructor(init_sprite_entity_from,
		destroy_sprite_entity,
		sizeof(t_sprite_entity),
		&args));
}
