/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:03:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:40:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sizes/isize.h"

t_isize	ft_isize(ssize_t x, ssize_t y)
{
	t_isize	retval;

	retval.x = x;
	retval.y = y;
	return (retval);
}
