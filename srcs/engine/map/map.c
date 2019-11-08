/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:04:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:29:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_constructor	map(const char *const path)
{
	static t_map_args	args;

	args.path = path;
	return (ft_constructor(init_map, destroy_map, sizeof(t_map), &args));
}
