/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3i.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:17:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:18:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3I_H
# define VEC3I_H

/*
** Three-dimensional int vector
*/
typedef struct	s_vec3i
{
	int	x;
	int	y;
	int	z;
}				t_vec3i;

/*
** Constructors
*/
t_vec3i			ft_vec3i(int x, int y, int z);

#endif
