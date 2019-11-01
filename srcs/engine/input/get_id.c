/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:50:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 16:43:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "ft/str.h"

t_input_id	input_get_id(t_input *const self, const char *const key)
{
	size_t		i;
	size_t		table_size;
	t_input_set	*set;

	i = 0;
	table_size = self->table.size / sizeof(t_input_set);
	while (i < table_size)
	{
		set = (t_input_set*)self->table.data + i;
		if (ft_strcmp(set->key, key) == 0)
			return (set->id);
		i++;
	}
	return (INPUT_NULL_ID);
}
