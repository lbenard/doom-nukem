/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:49:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:50:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_u32	blend_add(const t_rgba *const back, const t_rgba *const front)
{
	return (ft_rgba(
		(1.0f - (front->c.a / 255.0f)) * back->c.r + front->c.r *
			(front->c.a / 255.0f),
		(1.0f - (front->c.a / 255.0f)) * back->c.g + front->c.g *
			(front->c.a / 255.0f),
		(1.0f - (front->c.a / 255.0f)) * back->c.b + front->c.b *
			(front->c.a / 255.0f),
		255).integer);
}
