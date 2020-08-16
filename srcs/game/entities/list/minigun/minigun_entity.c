/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigun_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:31:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 19:19:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minigun_entity.h"

t_constructor	minigun_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_minigun_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_minigun_entity,
		destroy_minigun_entity,
		sizeof(t_minigun_entity),
		&args));
}
