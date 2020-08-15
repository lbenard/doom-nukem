/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_radio_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:03:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/24 22:04:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"
#include "maths/maths.h"

t_result	init_radio_group(t_radio_group *const self,
				t_checkbox_entity **const list,
				const size_t size,
				const size_t default_checkbox)
{
	self->list = list;
	self->size = size;
	self->last = ft_smin(default_checkbox, size - 1);
	self->list[self->last]->is_checked = TRUE;
	return (OK);
}
