/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:13:42 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:19:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3d.h"

t_vec3d	vec3d_scalar(t_vec3d src, double a)
{
	src.x *= a;
	src.y *= a;
	src.z *= a;
	return (src);
}
