/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:29:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 22:47:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4D_H
# define VEC4D_H

# include "maths/vec3d.h"

typedef struct s_vec3d	t_vec3d;

/*
** Four-dimensional double vector
*/
typedef struct	s_vec4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec4d;

/*
** Constructors
*/
t_vec4d			ft_vec4d(double x, double y, double z, double w);

/*
** Operations
*/
double			vec4d_dot(t_vec4d a, t_vec4d b);
t_vec4d			vec4d_scalar(t_vec4d src, double a);

/*
** Casts
*/
t_vec3d			vec4d_to_vec3d(t_vec4d src);

#endif
