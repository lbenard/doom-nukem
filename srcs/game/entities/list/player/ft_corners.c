/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corners.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:06:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:16:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_corners	ft_corners(t_bool ne, t_bool se, t_bool so, t_bool no)
{
	t_corners corners;

	corners.ne = ne;
	corners.se = se;
	corners.so = so;
	corners.no = no;
	return (corners);
}
