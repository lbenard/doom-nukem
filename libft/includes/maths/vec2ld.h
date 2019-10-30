/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2ld.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:31:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:42:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2LD_H
# define VEC2LD_H

/*
** Two-dimensional long double vector
*/
typedef struct	s_vec2ld
{
	long double	x;
	long double	y;
}				t_vec2ld;

/*
** Constructors
*/
t_vec2ld		ft_vec2ld(long double x, long double y);

/*
** Operations
*/
long double		vec2ld_dot(t_vec2ld a, t_vec2ld b);
t_vec2ld		vec2ld_scalar(t_vec2ld src, long double a);
long double		vec2ld_distance(t_vec2ld a, t_vec2ld b);

#endif
