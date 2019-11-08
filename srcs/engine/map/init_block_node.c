/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:55 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/06 19:55:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"

static t_result	is_values_amount_correct(char **values)
{
	size_t	values_amount;

	values_amount = 0;
	while (values[values_amount])
		values_amount++;
	if (values_amount != 4)
	{
		return (throw_result_str("is_values_amount_correct()",
			"bad amount of values in block node"));
	}
	return (OK);
}

static t_result	check_args(const char *key, char **values)
{
	if (!key)
	{
		dn_free_values(values);
		return (throw_result_str("check_args()", "invalid key"));
	}
	if (!values)
	{
		free((char*)key);
		return (throw_result_str("check_args()", "invalid values"));
	}
	if (is_values_amount_correct(values) == ERROR)
	{
		dn_free_values(values);
		free((char*)key);
		return (throw_result_str("check_args()", "invalid amount"));
	}
	return (OK);
}

t_result		init_block_node(t_block_node *const self,
					const t_block_node_args *const args)
{
	if (check_args(args->key, args->values) == ERROR)
	{
		return (throw_result_str("init_block_node()",
			"failed while initializing values"));
	}
	init_list_head(&self->node);
	self->key = args->key[0];
	self->north_texture_name = args->values[0];
	self->east_texture_name = args->values[1];
	self->south_texture_name = args->values[2];
	self->west_texture_name = args->values[3];
	free(args->values);
	free((char*)args->key);
	return (OK);
}
