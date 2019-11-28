/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_opaque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:19:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/28 17:48:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"
#include "maths/maths.h"
#include "ft/mem.h"

static t_usize	frame_size(const t_frame *const self,
					const t_frame *const layer,
					const t_isize pos)
{
	t_usize	ret;

	ret.x = ft_min(pos.x + layer->size.x, self->size.x) - ft_max(pos.x, 0);
	ret.y = ft_min(pos.y + layer->size.y, self->size.y) - ft_max(pos.y, 0);
	return (ret);
}

static t_bool	is_visible(const t_frame *const bg,
					const t_frame *const fg,
					const t_isize pos)
{
	return (!(pos.x >= (ssize_t)bg->size.x || pos.y >= (ssize_t)bg->size.y
		|| pos.x + (ssize_t)fg->size.x <= 0
		|| pos.y + (ssize_t)fg->size.y <= 0));
}

void			frame_layer_opaque(t_frame *const bg,
					const t_frame *const fg,
					const t_isize pos)
{
	size_t	i;
	t_usize	size;
	t_usize	shift;

	if (is_visible(bg, fg, pos) == FALSE)
		return ;
	size = frame_size(bg, fg, pos);
	shift = ft_usize((pos.x < 0) ? -pos.x : 0, (pos.y < 0) ? -pos.y : 0);
	i = 0;
	while (i < size.y)
	{
		ft_memcpy((t_u32*)bg->frame.array + bg->size.x * (pos.y + shift.y + i)
			+ pos.x + shift.x,
			(t_u32*)fg->frame.array + fg->size.x * (shift.y + i) + shift.x,
			sizeof(t_u32) * size.x);
		i++;
	}
}
