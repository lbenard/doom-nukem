/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:43:31 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 17:45:58 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"

t_constructor	fireball_entity(const t_vec3f pos, const t_vec3f direction,
	t_player_entity *player_ref)
{
	static t_fireball_entity_args args;

	args.pos = pos;
	args.direction = direction;
	args.texture_path = "resources/sprites/fireball.bmp";
	args.player_ref = player_ref;
	return (ft_constructor(init_fireball_entity, destroy_fireball_entity,
		sizeof(t_fireball_entity), &args));
}
