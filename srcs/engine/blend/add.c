/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:49:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 01:16:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_rgba	blend_add(const t_rgba back, const t_rgba front)
{
	t_rgba	result;
	float	opacity;
	float	diff;

	if (front.c.a == 255)
		return (front);
	else if (front.c.a == 0)
		return (back);
	opacity = front.c.a / 255.0f;
	diff = 1.0f - opacity;
	result.c.r = diff * back.c.r + front.c.r * opacity;
	result.c.g = diff * back.c.g + front.c.g * opacity;
	result.c.b = diff * back.c.b + front.c.b * opacity;
	result.c.a = COLOR_OPAQUE;
	return (result);
}
