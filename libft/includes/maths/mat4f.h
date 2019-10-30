/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:26:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:39:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4F_H
# define MAT4F_H

# include "maths/vec3f.h"
# include "maths/vec4f.h"

/*
** Four-dimensional float matrix
*/
typedef union	u_mat4f
{
	struct		s_mat4f_data
	{
		float	m00;
		float	m01;
		float	m02;
		float	m03;
		float	m10;
		float	m11;
		float	m12;
		float	m13;
		float	m20;
		float	m21;
		float	m22;
		float	m23;
		float	m30;
		float	m31;
		float	m32;
		float	m33;
	}			d;
	float		m[4][4];
}				t_mat4f;

/*
** Constructors
*/
t_mat4f			ft_mat4f(void);
t_mat4f			ft_mat4f_identity(void);
t_mat4f			ft_mat4f_translation(t_vec3f translation);
t_mat4f			ft_mat4f_scaling(t_vec3f scaling);
t_mat4f			ft_mat4f_rotation(t_vec3f rotation);

/*
** Operations
*/
t_mat4f			mat4f_x_mat4f(t_mat4f a, t_mat4f b);
t_vec4f			mat4f_x_vec4(t_mat4f a, t_vec4f b);

#endif
