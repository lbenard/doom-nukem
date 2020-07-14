/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/07/08 20:51:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"

static t_result	check_args(const char *key, const char *texture_path)
{
	if (!key)
		return (throw_result_str("check_args()", "invalid key"));
	if (!texture_path)
		return (throw_result_str("check_args()", "invalid values"));
	return (OK);
}

t_result		init_block_node(t_block_node *const self,
					const t_block_node_args *const args)
{
	if (check_args(args->key, args->texture_path) == ERROR)
	{
		free((char*)args->key);
		free((char*)args->texture_path);
		return (throw_result_str("init_block_node()",
			"failed while initializing values"));
	}
	init_module(&self->module);
	init_list_head(&self->node);
	self->key = args->key[0];
	self->texture_path = args->texture_path;
	free((char*)args->key);
	return (OK);
}
