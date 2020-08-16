/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_squared_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:48:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 22:49:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3f.h"

float	vec3f_squared_distance(t_vec3f a, t_vec3f b)
{
	return ((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
		+ (a.z - b.z) * (a.z - b.z));
}
