/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:03:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:03:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/module.h"

static t_result	construct_module(void *const module,
					const t_constructor constructor)
{
	if (constructor.args)
		return (constructor.constructor_fn(module, constructor.args));
	else
		return (constructor.constructor_fn(module));
}

void			module_add(t_module *const self,
					void *const module,
					const t_constructor constructor)
{
	t_module_node	*node;

	if (self->has_error)
		return ;
	if (!(node = (t_module_node*)malloc(sizeof(t_module_node))))
	{
		self->has_error = TRUE;
		return ;
	}
	if (construct_module(module, constructor) == ERROR)
	{
		free(node);
		self->has_error = TRUE;
		return ;
	}
	init_module_node(node, module, constructor.destructor_fn);
	list_add_entry(&node->node, &self->modules);
}