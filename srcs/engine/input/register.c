/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:58:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:25:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "engine/error.h"
#include "ft/str.h"

static t_bool	is_key_in_table(t_vector *const table, const char *const key)
{
	size_t		i;
	size_t		table_size;
	t_input_set	*set;

	i = 0;
	table_size = table->size / sizeof(t_input_set);
	while (i < table_size)
	{
		set = (t_input_set*)table->data + i;
		if (ft_strcmp(set->key, key) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void			input_register(t_input *const self, const char *const key)
{
	t_input_set	set;

	if (is_key_in_table(&self->table, key))
		return ;
	set = ft_input_set(key, input_set_get_uid());
	if (vector_push_back(&self->table, &set, sizeof(t_input_set)) == ERROR)
	{
		throw_error_str("input_register()", "failed to add set in input table");
		self->module.has_error = TRUE;
		return ;
	}
}
