/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:06:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:43:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgb.h"

t_rgb	ft_rgb_int(t_u32 color)
{
	t_rgb	result;

	result.b = color;
	result.g = color >> 8;
	result.r = color >> 16;
	return (result);
}
