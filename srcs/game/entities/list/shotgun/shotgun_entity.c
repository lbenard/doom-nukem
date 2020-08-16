/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shotgun_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:31:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 02:44:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/shotgun_entity.h"

t_constructor	shotgun_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_shotgun_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_shotgun_entity,
		destroy_shotgun_entity,
		sizeof(t_shotgun_entity),
		&args));
}
