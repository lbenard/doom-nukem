/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4f_scaling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:01:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat4f.h"

t_mat4f	ft_mat4f_scaling(t_vec3f scaling)
{
	float	x;
	float	y;
	float	z;

	x = scaling.x;
	y = scaling.y;
	z = scaling.z;
	return ((t_mat4f)(struct s_mat4f_data) {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	});
}
