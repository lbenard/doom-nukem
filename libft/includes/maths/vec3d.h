/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:28:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:41:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3D_H
# define VEC3D_H

# include "maths/vec2d.h"
# include "maths/vec4d.h"

typedef struct s_vec4d	t_vec4d;

/*
** Three-dimensional double vector
*/
typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

/*
** Constructors
*/
t_vec3d			ft_vec3d(double x, double y, double z);

/*
** Operations
*/
double			vec3d_dot(t_vec3d a, t_vec3d b);
t_vec3d			vec3d_scalar(t_vec3d src, double a);
double			vec3d_distance(t_vec3d a, t_vec3d b);

/*
** Casts
*/
t_vec2d			vec3d_to_vec2d(t_vec3d src);
t_vec4d			vec3d_to_vec4d(t_vec3d src);

#endif
