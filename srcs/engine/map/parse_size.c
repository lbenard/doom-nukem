/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:03:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:55:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"
#include "ft/str.h"
#include "maths/maths.h"

t_result	map_parse_size(t_map *const self, char *size_flag_str)
{
	int		height;
	int		width;
	char	*p;

	if (!size_flag_str)
	{
		return (throw_result_str("map_parse_size()",
			"invalid size flag string"));
	}
	p = size_flag_str;
	if (!ft_strstr(p, "height: ") || !ft_strstr(p, "width: "))
	{
		free(size_flag_str);
		return (throw_result_str("map_parse_size()", "invalid key"));
	}
	height = ft_atoi(ft_strstr(p, "height: ") + ft_strlen("height: "));
	width = ft_atoi(ft_strstr(p, "width: ") + ft_strlen("width: "));
	free(size_flag_str);
	if (height < 3 || width < 3)
		return (ERROR);
	self->size.x = width;
	self->size.y = height;
	return (OK);
}
