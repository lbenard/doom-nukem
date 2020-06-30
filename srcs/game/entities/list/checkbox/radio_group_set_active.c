/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radio_group_set_active.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 02:29:22 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 02:30:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	radio_group_set_active(t_radio_group *const self,
			const t_bool state)
{
	size_t	i;

	i = 0;
	while (i < self->size)
	{
		self->list[i]->is_active = state;
		i++;
	}
}