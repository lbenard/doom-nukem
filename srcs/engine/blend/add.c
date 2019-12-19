/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:49:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/03 08:25:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_rgba	blend_add(const t_rgba back, const t_rgba front)
{
	t_rgba	result;

	result.c.r = (1.0f - (front.c.a / 255.0f)) * back.c.r + front.c.r *
		(front.c.a / 255.0f);
	result.c.g = (1.0f - (front.c.a / 255.0f)) * back.c.g + front.c.g *
		(front.c.a / 255.0f);
	result.c.b = (1.0f - (front.c.a / 255.0f)) * back.c.b + front.c.b *
		(front.c.a / 255.0f);
	result.c.a = COLOR_OPAQUE;
	return (result);
}
