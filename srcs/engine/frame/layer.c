/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:39:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/07 19:39:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"
#include "maths/maths.h"

static t_usize	frame_size(t_frame *const self,
					t_frame *const layer,
					const t_isize pos)
{
	t_usize	ret;

	ret.x = ft_min(pos.x + layer->size.x, self->size.x) - ft_max(pos.x, 0);
	ret.y = ft_min(pos.y + layer->size.y, self->size.y) - ft_max(pos.y, 0);
	return (ret);
}

void			frame_layer(t_frame *const self,
					t_frame *const layer,
					const t_isize pos,
					t_u32 (*const blend)
						(const t_rgba *const back, const t_rgba *const front))
{
	t_usize	shift;
	t_usize	size;
	size_t	position;
	t_usize	i;

	if (pos.x >= (ssize_t)self->size.x || pos.y >= (ssize_t)self->size.y
		|| pos.x + (ssize_t)layer->size.x <= 0
		|| pos.y + (ssize_t)layer->size.y <= 0)
		return ;
	shift = ft_usize((pos.x < 0) ? -pos.x : 0, (pos.y < 0) ? -pos.y : 0);
	size = frame_size(self, layer, pos);
	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			position = self->size.x * (pos.y + shift.y + i.y)
				+ (pos.x + shift.x + i.x);
			((t_u32*)self->frame.array)[position] = blend(
				(t_rgba*)self->frame.array + position,
				(t_rgba*)layer->frame.array + layer->size.x * (shift.y + i.y)
					+ (shift.x + i.x));
			i.x++;
		}
		i.y++;
	}
}
