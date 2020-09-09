/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:19:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 00:32:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"
#include "engine/map.h"
#include "engine/error.h"

static char	floor_value(char *room_flag_str)
{
	char	floor;
	char	*floor_str;

	floor = 0;
	if ((floor_str = ft_strstr(room_flag_str, "floor: ")))
	{
		floor_str += ft_strlen("floor: ");
		if (block_from_key(floor_str[0]))
			floor = floor_str[0];
	}
	return (floor);
}

static char	ceiling_value(char *room_flag_str)
{
	char	ceiling;
	char	*ceiling_str;

	ceiling = 0;
	if ((ceiling_str = ft_strstr(room_flag_str, "ceiling: ")))
	{
		ceiling_str += ft_strlen("ceiling: ");
		if (block_from_key(ceiling_str[0]))
			ceiling = ceiling_str[0];
	}
	return (ceiling);
}

t_result	map_parse_room(t_map *const self, char *room_flag_str)
{
	char	*p;

	if (!room_flag_str)
	{
		return (throw_result_str("map_parse_room()",
			"invalid size flag string"));
	}
	p = room_flag_str;
	self->floor = floor_value(p);
	self->ceiling = ceiling_value(p);
	free(room_flag_str);
	return (OK);
}
