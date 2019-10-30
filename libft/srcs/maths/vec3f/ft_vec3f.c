/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:08:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:12:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3f.h"

t_vec3f	ft_vec3f(float x, float y, float z)
{
	t_vec3f	retval;

	retval.x = x;
	retval.y = y;
	retval.z = z;
	return (retval);
}
