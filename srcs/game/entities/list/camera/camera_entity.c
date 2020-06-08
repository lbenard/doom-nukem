/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:44:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/01 14:46:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/camera_entity.h"

t_constructor	camera_entity(const t_vec2f spawn_pos, const float direction)
{
	static t_camera_entity_args	args;

	args.spawn_pos = spawn_pos;
	args.direction = direction;
	return (ft_constructor(
		init_camera_entity,
		destroy_camera_entity,
		sizeof(t_camera_entity),
		&args));
}