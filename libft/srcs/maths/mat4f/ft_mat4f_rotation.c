/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4f_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:48:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:09:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/mat4f.h"

static t_mat4f	xaxis_rot(float x)
{
	t_mat4f	mat;
	float	c;
	float	s;

	c = cos(x);
	s = sin(x);
	mat.d = (struct s_mat4f_data) {
		1, 0, +0, 0,
		0, c, -s, 0,
		0, s, +c, 0,
		0, 0, +0, 1
	};
	return (mat);
}

static t_mat4f	yaxis_rot(float y)
{
	t_mat4f	mat;
	float	c;
	float	s;

	c = cos(y);
	s = sin(y);
	mat.d = (struct s_mat4f_data) {
		+c, 0, s, 0,
		+0, 1, 0, 0,
		-s, 0, c, 0,
		+0, 0, 0, 1
	};
	return (mat);
}

static t_mat4f	zaxis_rot(float z)
{
	t_mat4f	mat;
	float	c;
	float	s;

	c = cos(z);
	s = sin(z);
	mat.d = (struct s_mat4f_data) {
		c, -s, 0, 0,
		s, +c, 0, 0,
		0, +0, 1, 0,
		0, +0, 0, 1
	};
	return (mat);
}

t_mat4f			ft_mat4f_rotation(t_vec3f rotation)
{
	return (mat4f_x_mat4f(mat4f_x_mat4f(
		zaxis_rot(rotation.z),
		yaxis_rot(rotation.y)),
		xaxis_rot(rotation.x)));
}
