/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:21:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/08 20:48:27 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3F_H
# define VEC3F_H

# include "maths/vec2f.h"
# include "maths/vec4f.h"

typedef struct s_vec2f	t_vec2f;
typedef struct s_vec4f	t_vec4f;

/*
** Three-dimensional float vector
*/
typedef struct	s_vec3f
{
	float	x;
	float	y;
	float	z;
}				t_vec3f;

/*
** Constructors
*/
t_vec3f			ft_vec3f(float x, float y, float z);

/*
** Operations
*/
float			vec3f_dot(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_scalar(t_vec3f src, float a);
float			vec3f_distance(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_normalize(t_vec3f src);
t_vec3f			vec3f_addition(t_vec3f a, t_vec3f b);

/*
** Casts
*/
t_vec2f			vec3f_to_vec2f(t_vec3f src);
t_vec4f			vec3f_to_vec4f(t_vec3f src);

#endif
