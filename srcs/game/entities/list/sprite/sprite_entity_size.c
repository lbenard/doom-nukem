/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_entity_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:20:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 02:21:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"

t_constructor	sprite_entity_size(const t_vec3f pos, const t_usize sprite_size)
{
	static t_sprite_entity_args	args;

	args.pos = pos;
	args.sprite_size = sprite_size;
	return (ft_constructor(init_sprite_entity_size,
		destroy_sprite_entity,
		sizeof(t_sprite_entity),
		&args));
}
