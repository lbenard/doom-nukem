/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:18:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/06 19:07:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weapon_entity.h"

t_constructor	weapon_entity(const t_spritesheet *const spritesheet_ref,
					const char *const icon_path,
					const t_weapon_specs specs,
					t_raycasting_scene *const ctx)
{
	static t_weapon_entity_args	args;

	args.spritesheet_ref = spritesheet_ref;
	args.icon_path = icon_path;
	args.specs = specs;
	args.ctx = ctx;
	return (ft_constructor(init_weapon_entity,
		destroy_weapon_entity,
		sizeof(t_weapon_entity),
		&args));
}