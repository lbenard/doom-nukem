/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isize.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:25:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 16:13:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISIZE_H
# define ISIZE_H

# include <string.h>
# ifdef __linux__
#  include <sys/types.h>
# endif

/*
** 2D signed size
*/
typedef struct	s_isize
{
	ssize_t	x;
	ssize_t	y;
}				t_isize;

/*
** Constructors
*/
t_isize			ft_isize(ssize_t x, ssize_t y);

#endif
