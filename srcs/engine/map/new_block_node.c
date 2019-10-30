/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:55 by ppetitea          #+#    #+#             */
/*   Updated: 2019/10/05 12:04:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"

t_result		is_values_amount_correct(char **values)
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

t_result		check_args(const char *key, char **values)
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

t_block_node	*new_block_node(const char *key, char **values)
{
	t_block_node	*ret;

	if (check_args(key, values) == ERROR)
	{
		return (throw_error_str("new_block_node()",
			"failed while initializing values"));
	}
	if (!(ret = (t_block_node*)malloc(sizeof(t_block_node))))
	{
		free((char*)key);
		dn_free_values(values);
		return (throw_error_str("new_block_node()",
			"failed while allocating block node"));
	}
	init_list_head(&ret->node);
	ret->key = key[0];
	ret->north_texture_name = values[0];
	ret->east_texture_name = values[1];
	ret->south_texture_name = values[2];
	ret->west_texture_name = values[3];
	free(values);
	free((char*)key);
	return (ret);
}
