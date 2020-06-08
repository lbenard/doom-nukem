/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:18:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/22 20:19:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/sector_scene.h"

t_constructor	sector_scene(void)
{
	return (ft_constructor(init_sector_scene,
		destroy_sector_scene,
		sizeof(t_sector_scene),
		NULL));
}