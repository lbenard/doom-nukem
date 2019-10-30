/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:26:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:39:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2D_H
# define VEC2D_H

/*
** Two-dimensional double vector
*/
typedef struct	s_vec2d
{
	double	x;
	double	y;
}				t_vec2d;

/*
** Constructors
*/
t_vec2d			ft_vec2d(double x, double y);

/*
** Operations
*/
double			vec2d_dot(t_vec2d a, t_vec2d b);
t_vec2d			vec2d_scalar(t_vec2d src, double a);
double			vec2d_distance(t_vec2d a, t_vec2d b);

#endif
