/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3f_x_mat3f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:10:42 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:58:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "maths/mat3f.h"

t_mat3f	mat3f_x_mat3f(t_mat3f a, t_mat3f b)
{
	t_mat3f	result;
	size_t	x;
	size_t	y;

	result = ft_mat3f();
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			result.m[y][x] = a.m[y][0] * b.m[0][x] +
				a.m[y][1] * b.m[1][x] +
				a.m[y][2] * b.m[2][x];
			x++;
		}
		y++;
	}
	return (result);
}
