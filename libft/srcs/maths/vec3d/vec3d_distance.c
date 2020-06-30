/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:41:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:54:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/vec3d.h"

double	vec3d_distance(t_vec3d a, t_vec3d b)
{
	return (sqrt(
		(a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
		+ (a.z - b.z) * (a.z - b.z)));
}
