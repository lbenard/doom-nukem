/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weird_alien_entity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:47:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:17:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weird_alien_entity.h"

t_constructor	weird_alien_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_weird_alien_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_weird_alien_entity,
		destroy_weird_alien_entity,
		sizeof(t_weird_alien_entity),
		&args));
}
