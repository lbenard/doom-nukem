/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:39:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:54:25 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/vec2d.h"

double	vec2d_distance(t_vec2d a, t_vec2d b)
{
	return (sqrt(
		(a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)));
}
