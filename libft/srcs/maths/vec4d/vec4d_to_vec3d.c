/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d_to_vec3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:18:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:23:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec4d.h"

t_vec3d	vec4d_to_vec3d(t_vec4d src)
{
	t_vec3d	dst;

	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
	return (dst);
}
