/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_radio_group.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:06:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/24 22:14:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

static void	reset(t_radio_group *const self)
{
	size_t	i;

	i = 0;
	while (i < self->size)
	{
		self->list[i]->is_checked = FALSE;
		i++;
	}
}

void		update_radio_group(t_radio_group *const self)
{
	size_t				i;
	t_checkbox_entity	*checkbox;

	i = 0;
	while (i < self->size)
	{
		checkbox = self->list[i];
		if (checkbox->is_checked && i != self->last)
		{
			reset(self);
			checkbox->is_checked = TRUE;
			self->last = i;
			break ;
		}
		i++;
	}
	self->list[self->last]->is_checked = TRUE;
}
