/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:29:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 19:10:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_fill(t_frame *const self, const t_rgba fill_color)
{
	size_t	i;
	size_t	total_size;

	i = 0;
	total_size = self->size.x * self->size.y;
	while (i < total_size)
	{
		((t_rgba*)self->frame.array)[i] = fill_color;
		i++;
	}
}
