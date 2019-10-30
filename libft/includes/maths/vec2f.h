/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:19:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:32:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2F_H
# define VEC2F_H

/*
** Two-dimensional float vector
*/
typedef struct	s_vec2f
{
	float	x;
	float	y;
}				t_vec2f;

/*
** Constructors
*/
t_vec2f			ft_vec2f(float x, float y);

/*
** Operations
*/
float			vec2f_dot(t_vec2f a, t_vec2f b);
t_vec2f			vec2f_scalar(t_vec2f src, float a);
float			vec2f_distance(t_vec2f a, t_vec2f b);

#endif
