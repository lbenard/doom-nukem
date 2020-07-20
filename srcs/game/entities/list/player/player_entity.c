/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:14:55 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/20 02:46:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/entities/player_entity.h"

t_constructor	player_entity(const t_map *const map, const float fov)
{
	static t_player_entity_args	args;

	args.map = map;
	args.fov = tan(fov / 2.0f);
	return (ft_constructor(init_player_entity,
		destroy_player_entity,
		sizeof(t_player_entity),
		&args));
}
