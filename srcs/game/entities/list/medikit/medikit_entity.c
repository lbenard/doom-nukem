/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medikit_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 00:23:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/medikit_entity.h"

t_constructor	medikit_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_medikit_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_medikit_entity,
		destroy_medikit_entity,
		sizeof(t_medikit_entity),
		&args));
}
