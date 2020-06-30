/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:46:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:52:22 by mribouch         ###   ########.fr       */
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
