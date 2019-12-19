/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:12:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 22:37:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_utils.h"

void	render_column(t_frame *const frame,
			const t_usize start,
			const size_t length,
			const t_rgba color)
{
	size_t	i;

	i = 0;
	if (start.x < frame->size.x
		&& start.y < frame->size.y)
	while (i < length && start.y + i < frame->size.y)
	{
		((t_rgba*)frame->frame.array)[frame->size.x * (start.y + i) + start.x]
			= color;
		i++;
	}
}