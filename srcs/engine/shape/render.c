/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:01:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/21 09:47:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"
#include "maths/maths.h"

void	shape_render(const t_shape *const self,
			const t_isize pos,
			t_frame *const framebuffer,
			const t_rgba color)
{
	t_isize	i;
	t_rgba	*pixel;

	i.y = ft_ssmax(self->box.pos.y, 0);
	while (i.y < (ssize_t)self->box.size.y + self->box.pos.y
		&& i.y + pos.y < (ssize_t)framebuffer->size.y)
	{
		i.x = ft_ssmax(self->box.pos.x, 0);
		while (i.x < (ssize_t)self->box.size.x  + self->box.pos.x
			&& i.x + pos.x < (ssize_t)framebuffer->size.x)
		{
			if (shape_is_point_in_shape(self, ft_isize(i.x, i.y)))
			{
				pixel = ((t_rgba*)framebuffer->frame.array)
					+ framebuffer->size.x * (i.y + pos.y) + (i.x + pos.x);
				*pixel = blend_add(*pixel, color);
			}
			i.x++;
		}
		i.y++;
	}
}