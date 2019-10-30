/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:57:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:38:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT3F_H
# define MAT3F_H

# include "maths/vec3f.h"

/*
** Three-dimensional float matrix
*/
typedef union	u_mat3f
{
	struct		s_mat3f_data
	{
		float	m00;
		float	m01;
		float	m02;
		float	m10;
		float	m11;
		float	m12;
		float	m20;
		float	m21;
		float	m22;
	}			d;
	float		m[3][3];
}				t_mat3f;

/*
** Constructors
*/
t_mat3f			ft_mat3f(void);
t_mat3f			ft_mat3f_identity(void);

/*
** Operations
*/
t_mat3f			mat3f_x_mat3f(t_mat3f a, t_mat3f b);
t_vec3f			mat3f_x_vec3f(t_mat3f a, t_vec3f b);

#endif
