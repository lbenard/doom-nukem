/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4i.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:18:42 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:19:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4I_H
# define VEC4I_H

/*
** Four-dimensional int vector
*/
typedef struct	s_vec4i
{
	int	x;
	int	y;
	int	z;
	int	w;
}				t_vec4i;

/*
** Constructors
*/
t_vec4i			ft_vec4i(int x, int y, int z, int w);

#endif
