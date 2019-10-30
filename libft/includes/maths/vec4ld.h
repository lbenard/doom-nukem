/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4ld.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:34:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 22:47:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4LD_H
# define VEC4LD_H

# include "maths/vec3ld.h"

typedef struct s_vec3ld	t_vec3ld;

/*
** Four-dimensional long double vector
*/
typedef struct	s_vec4ld
{
	long double	x;
	long double	y;
	long double	z;
	long double	w;
}				t_vec4ld;

/*
** Constructors
*/
t_vec4ld		ft_vec4ld(long double x, long double y, long double z,
	long double w);

/*
** Operations
*/
long double		vec4ld_dot(t_vec4ld a, t_vec4ld b);
t_vec4ld		vec4ld_scalar(t_vec4ld src, long double a);

/*
** Casts
*/
t_vec3ld		vec4ld_to_vec3ld(t_vec4ld src);

#endif
