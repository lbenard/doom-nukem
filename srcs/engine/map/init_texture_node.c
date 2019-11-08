/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:24:09 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/06 15:33:19 by lbenard          ###   ########.fr       */
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
		return (throw_result_str("new_texture_node()", "incorrect argument"));
	}
	if (static_module_create(&self->image, image(args->path)) == ERROR)
	{
		free((char*)args->key);
		free((char*)args->path);
		return (throw_result_str("new_texture_node()",
			"failed while creating image"));
	}
	free((char*)args->path);
	init_list_head(&self->node);
	self->key = args->key;
	return (OK);
}
