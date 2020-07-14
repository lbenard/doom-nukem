/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:24:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/07/06 23:43:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"

t_result	init_texture_node(t_texture_node *const self,
				const t_texture_node_args *const args)
{
	if (!args->path || !args->key)
	{
		free((char*)args->key);
		free((char*)args->path);
		return (throw_result_str("init_texture_node()", "incorrect argument"));
	}
	init_module(&self->module);
	module_add(&self->module, &self->texture, frame_from_file(args->path));
	free((char*)args->path);
	init_list_head(&self->node);
	self->key = args->key;
	if (self->module.has_error)
	{
		destroy_texture_node(self);
		return (throw_result_str("init_texture_node()",
			"failed to create new texture node"));
	}
	return (OK);
}
