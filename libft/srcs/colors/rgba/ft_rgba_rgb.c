/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:46:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 15:34:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgba.h"

t_rgba	ft_rgba_rgb(t_rgb color)
{
	t_rgba	ret;

	ret.c.r = color.r;
	ret.c.g = color.g;
	ret.c.b = color.b;
	ret.c.a = 255;
	return (ret);
}