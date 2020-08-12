/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_entity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:43:31 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 14:40:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"

t_constructor	fireball_entity(const t_vec3f pos, const t_vec3f direction)
{
	static t_fireball_entity_args args;

	args.pos = pos;
	args.direction = direction;
	return (ft_constructor(init_fireball_entity, destroy_fireball_entity,
		sizeof(t_fireball_entity), &args));
}
