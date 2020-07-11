/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:37:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 19:39:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"
#include "maths/maths.h"

t_result		map_parse_player(t_map *const self, char *player_flag_str)
{
	char	**spawn_str;

	if (!player_flag_str)
		return (throw_result_str("parse_player()", "flag is incorrect"));
	spawn_str = dn_get_values(ft_strstr(player_flag_str, "spawn: "), ' ');
	free(player_flag_str);
	if (!spawn_str || dn_strsplit_length(spawn_str) != 2)
	{
		dn_free_values(spawn_str);
		return (throw_result_str("parse_player()", "bad player_spawn data"));
	}
	self->spawn = ft_vec2d(ft_atof(spawn_str[0]), ft_atof(spawn_str[1]));
	if (self->spawn.x < 0.0f || self->spawn.x >= self->size.x ||
		self->spawn.y < 0.0f || self->spawn.y >= self->size.y)
	{
		dn_free_values(spawn_str);
		return (throw_result_str("parse_player()",
			"player is outside the map"));
	}
	dn_free_values(spawn_str);
	return (OK);
}
