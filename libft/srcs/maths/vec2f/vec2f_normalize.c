/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:36:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/14 06:37:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/vec2f.h"

t_vec2f	vec2f_normalize(t_vec2f src)
{
	float	w;

	w = sqrt(src.x * src.x + src.y * src.y);
	if (w == 0)
		return (src);
	src.x /= w;
	src.y /= w;
	return (src);
}