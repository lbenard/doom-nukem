/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:09:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:26:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_utils.h"

void	render_row(t_frame *const frame,
			const t_usize start,
			const size_t length,
			const t_rgba color)
{
	size_t	i;
	t_rgba	*ptr;

	i = 0;
	if (start.x < frame->size.x && start.y < frame->size.y)
	{
		while (i < length && start.x + i < frame->size.x)
		{
			ptr = ((t_rgba*)frame->frame.array) + frame->size.x * start.y
				+ start.x + i;
			*ptr = blend_add(*ptr, color);
			i++;
		}
	}
}
