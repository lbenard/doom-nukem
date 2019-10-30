/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 07:21:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

t_smodule_factory	raycasting(const t_usize window_size, t_map *const map)
{
	static t_raycasting_args	args;

	args.window_size = window_size;
	args.map = map;
	return (ft_smodule_factory(ft_smodule_descriptor(
		init_raycasting, destroy_raycasting), &args));
}
