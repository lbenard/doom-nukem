/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3f_x_vec3f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:39:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:57:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat3f.h"
#include "maths/vec3f.h"

t_vec3f	ft_mat3f_x_vec3f(t_mat3f a, t_vec3f b)
{
	t_vec3f	result;

	result.x = a.m[0][0] * b.x +
		a.m[0][1] * b.y +
		a.m[0][2] * b.z;
	result.y = a.m[1][0] * b.x +
		a.m[1][1] * b.y +
		a.m[1][2] * b.z;
	result.z = a.m[2][0] * b.x +
		a.m[2][1] * b.y +
		a.m[2][2] * b.z;
	return (result);
}
