/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:28:32 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:26:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec4ld.h"

t_vec4ld	ft_vec4ld(long double x, long double y, long double z,
	long double w)
{
	t_vec4ld	retval;

	retval.x = x;
	retval.y = y;
	retval.z = z;
	retval.w = w;
	return (retval);
}
