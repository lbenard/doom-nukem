/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:10:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:17:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2d.h"

t_vec2d	ft_vec2d(double x, double y)
{
	t_vec2d	retval;

	retval.x = x;
	retval.y = y;
	return (retval);
}
