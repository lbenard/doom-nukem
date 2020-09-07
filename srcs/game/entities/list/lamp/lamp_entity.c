/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lamp_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 04:11:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/lamp_entity.h"

t_constructor	lamp_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_lamp_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_lamp_entity,
		destroy_lamp_entity,
		sizeof(t_lamp_entity),
		&args));
}
