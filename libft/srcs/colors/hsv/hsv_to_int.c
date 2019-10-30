/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:11:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 18:14:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/hsv.h"
#include "colors/rgb.h"

t_u32	hsv_to_int(t_hsv color)
{
	return (rgb_to_int(ft_rgb_hsv(color)));
}
