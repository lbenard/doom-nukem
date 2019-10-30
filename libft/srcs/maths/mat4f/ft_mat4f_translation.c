/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4f_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:27:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/22 14:53:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat4f.h"

t_mat4f	ft_mat4f_translation(t_vec3f translation)
{
	float	x;
	float	y;
	float	z;

	x = translation.x;
	y = translation.y;
	z = translation.z;
	return ((t_mat4f)(struct s_mat4f_data) {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	});
}
