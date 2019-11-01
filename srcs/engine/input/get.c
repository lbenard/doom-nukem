/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:06:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 16:43:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

float	input_get(t_input *const self, const t_input_id id)
{
	size_t		i;
	size_t		table_size;
	t_input_set	*set;

	i = 0;
	table_size = self->table.size / sizeof(t_input_set);
	while (i < table_size)
	{
		set = (t_input_set*)self->table.data + i;
		if (set->id == id)
			return (set->value);
		i++;
	}
	return (0.0f);
}