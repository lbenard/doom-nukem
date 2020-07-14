/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:30:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 18:34:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_rgba	blend_invert(const t_rgba back, const t_rgba front)
{
	t_rgba	invert;

	invert.c.r = 255 - back.c.r;
	invert.c.g = 255 - back.c.g;
	invert.c.b = 255 - back.c.b;
	invert.c.a = front.c.a;
	return (blend_add(back, invert));
}