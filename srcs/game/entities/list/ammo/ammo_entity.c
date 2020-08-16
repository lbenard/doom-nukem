/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:33:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ammo_entity.h"

t_constructor	ammo_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_ammo_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_ammo_entity,
		destroy_ammo_entity,
		sizeof(t_ammo_entity),
		&args));
}
