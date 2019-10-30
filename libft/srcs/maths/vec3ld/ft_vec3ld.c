/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:24:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:25:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3ld.h"

t_vec3ld	ft_vec3ld(long double x, long double y, long double z)
{
	t_vec3ld	retval;

	retval.x = x;
	retval.y = y;
	retval.z = z;
	return (retval);
}
