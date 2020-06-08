/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:12:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/21 10:06:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_utils.h"
#include "engine/blend.h"

void	render_column(t_frame *const frame,
			const t_usize start,
			const size_t length,
			const t_rgba color)
{
	size_t	i;
	t_rgba	*ptr;

	i = 0;
	if (start.x < frame->size.x
		&& start.y < frame->size.y)
	while (i < length && start.y + i < frame->size.y)
	{
		ptr = ((t_rgba*)frame->frame.array) + frame->size.x * (start.y + i)
			+ start.x;
		*ptr = blend_add(*ptr, color);
		i++;
	}
}