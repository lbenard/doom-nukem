/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:31:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/06 18:32:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/pistol_entity.h"

t_constructor	pistol_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_pistol_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_pistol_entity,
		destroy_pistol_entity,
		sizeof(t_pistol_entity),
		&args));
}
