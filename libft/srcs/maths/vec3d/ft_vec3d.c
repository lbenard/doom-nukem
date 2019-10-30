/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:12:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:18:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3d.h"

t_vec3d	ft_vec3d(double x, double y, double z)
{
	t_vec3d	retval;

	retval.x = x;
	retval.y = y;
	retval.z = z;
	return (retval);
}
