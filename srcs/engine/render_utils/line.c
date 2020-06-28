/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:13:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:25:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_utils.h"
#include "maths/maths.h"

static void	pixel(t_frame *const frame, const t_isize pos, const t_rgba color)
{
	if (pos.x >= 0 && pos.x < (ssize_t)frame->size.x
		&& pos.y >= 0 && pos.y < (ssize_t)frame->size.y)
		((t_rgba*)frame->frame.array)[frame->size.x * pos.y + pos.x] = color;
}

static void	update_bresenham(int *const err,
				t_isize *const pos,
				t_isize d,
				t_isize s)
{
	int	e;

	e = *err;
	if (e > -d.x)
	{
		*err -= d.y;
		pos->x += s.x;
	}
	if (e < d.y)
	{
		*err += d.x;
		pos->y += s.y;
	}
}

void		render_line(t_frame *const frame,
				const t_isize start,
				const t_isize end,
				const t_rgba color)
{
	t_isize	pos;
	t_isize	d;
	t_isize	s;
	int		err;

	pos = ft_isize(start.x, start.y);
	d = ft_isize(ft_ssabs(end.x - start.x), ft_ssabs(end.y - start.y));
	s = ft_isize(pos.x < end.x ? 1 : -1, pos.y < end.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		pixel(frame, pos, color);
		if (pos.x == end.x && pos.y == end.y)
			break ;
		update_bresenham(&err, &pos, d, s);
	}
}
