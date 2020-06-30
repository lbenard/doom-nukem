/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:55:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 20:59:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"

t_constructor	sprite_entity(const t_vec3f pos,
					const char *texture_path)
{
	static t_sprite_entity_args	args;

	args.pos = pos;
	args.texture_path = texture_path;
	return (ft_constructor(init_sprite_entity,
		destroy_sprite_entity,
		sizeof(t_sprite_entity),
		&args));
}
