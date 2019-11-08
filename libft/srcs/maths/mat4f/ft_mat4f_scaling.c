/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4f_scaling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:38:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:08:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat4f.h"

t_mat4f	ft_mat4f_scaling(t_vec3f scaling)
{
	t_mat4f	mat;
	float	x;
	float	y;
	float	z;

	x = scaling.x;
	y = scaling.y;
	z = scaling.z;
	mat.d = (struct s_mat4f_data) {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	};
	return (mat);
}
