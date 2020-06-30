/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:02:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:54:05 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/vec3f.h"

t_vec3f	vec3f_normalize(t_vec3f src)
{
	float	w;

	w = sqrt(src.x * src.x + src.y * src.y + src.z * src.z);
	if (w == 0)
		return (src);
	src.x /= w;
	src.y /= w;
	src.z /= w;
	return (src);
}
