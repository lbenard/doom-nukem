/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_texture_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:24:09 by ppetitea          #+#    #+#             */
/*   Updated: 2019/10/03 23:52:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"

t_texture_node	*new_texture_node(const char *key, const char *const path)
{
	t_texture_node	*ret;

	if (!path || !key)
	{
		free((char*)key);
		free((char*)path);
		return (throw_error_str("new_texture_node()", "incorrect argument"));
	}
	if (!(ret = (t_texture_node*)malloc(sizeof(t_texture_node))))
	{
		free((char*)key);
		free((char*)path);
		return (throw_error_str("new_texture_node()",
			"failed while allocating texture node"));
	}
	if (!(ret->image = sfImage_createFromFile(path)))
	{
		free(ret);
		return (throw_error_str("new_texture_node()",
			"failed while creating image"));
	}
	free((char*)path);
	init_list_head(&ret->node);
	ret->key = key;
	return (ret);
}
