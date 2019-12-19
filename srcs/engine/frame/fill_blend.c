/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_blend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:58:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/03 12:34:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_fill_blend(t_frame *const self,
			const t_rgba fill_color,
			t_rgba (*const blend)(const t_rgba back,
				const t_rgba front))
{
	size_t	i;
	size_t	total_size;

	i = 0;
	total_size = self->size.x * self->size.y;
	while (i < total_size)
	{
		((t_rgba*)self->frame.array)[i] = blend(((t_rgba*)self->frame.array)[i],
			fill_color);
		i++;
	}
}
