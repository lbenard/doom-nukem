/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:16:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:17:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2I_H
# define VEC2I_H

/*
** Two-dimensional int vector
*/
typedef struct	s_vec2i
{
	int	x;
	int	y;
}				t_vec2i;

/*
** Constructors
*/
t_vec2i			ft_vec2i(int x, int y);

#endif
