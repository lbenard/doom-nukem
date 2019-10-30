/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:09:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:14:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec4f.h"

t_vec4f	ft_vec4f(float x, float y, float z, float w)
{
	t_vec4f	retval;

	retval.x = x;
	retval.y = y;
	retval.z = z;
	retval.w = w;
	return (retval);
}
