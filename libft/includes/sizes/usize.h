/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usize.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:25:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:10:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USIZE_H
# define USIZE_H

# include <string.h>

/*
** 2D unsigned size
*/
typedef struct	s_usize
{
	size_t	x;
	size_t	y;
}				t_usize;

/*
** Constructors
*/
t_usize			ft_usize(size_t x, size_t y);

#endif
