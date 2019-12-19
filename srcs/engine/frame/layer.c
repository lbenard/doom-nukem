/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:39:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/03 08:23:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"
#include "maths/maths.h"

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

void			frame_layer(t_frame *const bg,
					const t_frame *const fg,
					const t_isize pos,
					t_rgba (*const blend)
						(const t_rgba back, const t_rgba front))
{
	t_usize	i;
	t_usize	size;
	t_usize	shift;
	size_t	bg_pos;
	size_t	fg_pos;

	if (is_visible(bg, fg, pos) == FALSE)
		return ;
	size = frame_size(bg, fg, pos);
	shift = ft_usize((pos.x < 0) ? -pos.x : 0, (pos.y < 0) ? -pos.y : 0);
	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			bg_pos = bg->size.x * (pos.y + shift.y + i.y)
				+ (pos.x + shift.x + i.x);
			fg_pos = fg->size.x * (shift.y + i.y) + (shift.x + i.x);
			((t_rgba*)bg->frame.array)[bg_pos] = blend(((t_rgba*)
				bg->frame.array)[bg_pos], ((t_rgba*)fg->frame.array)[fg_pos]);
			i.x++;
		}
		i.y++;
	}
}
