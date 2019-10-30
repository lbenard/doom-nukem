/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f_x_mat4f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:25:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:04:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "maths/mat4f.h"

t_mat4f	mat4f_x_mat4f(t_mat4f a, t_mat4f b)
{
	t_mat4f	result;
	size_t	x;
	size_t	y;

	result = ft_mat4f();
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result.m[y][x] = a.m[y][0] * b.m[0][x] +
				a.m[y][1] * b.m[1][x] +
				a.m[y][2] * b.m[2][x] +
				a.m[y][3] * b.m[3][x];
			x++;
		}
		y++;
	}
	return (result);
}
