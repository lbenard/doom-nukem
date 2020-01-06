/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:01:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/06 00:33:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

void	shape_render(const t_shape *const self,
			const t_isize pos,
			t_frame *const framebuffer,
			const t_rgba color)
{
	t_usize	i;
	t_rgba	*pixel;

	i.y = 0;
	while (i.y < self->box.size.y && i.y + pos.y < framebuffer->size.y)
	{
		i.x = 0;
		while (i.x < self->box.size.x && i.x + pos.x < framebuffer->size.x)
		{
			if (shape_is_point_in_shape(self, ft_isize(i.x, i.y)))
			{
				pixel = ((t_rgba*)framebuffer->frame.array)
					+ framebuffer->size.x * (i.y + pos.y) + (i.x + pos.y);
				*pixel = blend_add(*pixel, color);
			}
			i.x++;
		}
		i.y++;
	}
}