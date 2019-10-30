/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3ld.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:32:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:43:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3LD_H
# define VEC3LD_H

# include "maths/vec2ld.h"
# include "maths/vec4ld.h"

typedef struct s_vec4ld	t_vec4ld;

/*
** Three-dimensional long double vector
*/
typedef struct	s_vec3ld
{
	long double	x;
	long double	y;
	long double	z;
}				t_vec3ld;

/*
** Constructors
*/
t_vec3ld		ft_vec3ld(long double x, long double y, long double z);

/*
** Operations
*/
long double		vec3ld_dot(t_vec3ld a, t_vec3ld b);
t_vec3ld		vec3ld_scalar(t_vec3ld src, long double a);
long double		vec3ld_distance(t_vec3ld a, t_vec3ld b);

/*
** Casts
*/
t_vec2ld		vec3ld_to_vec2ld(t_vec3ld src);
t_vec4ld		vec3ld_to_vec4ld(t_vec3ld src);

#endif
