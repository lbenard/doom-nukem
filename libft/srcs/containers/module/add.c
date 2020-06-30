/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:03:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:49:08 by mribouch         ###   ########.fr       */
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
	t_module	*module_ptr;

	if (self->has_error)
		return ;
	if (construct_module(module, constructor) == ERROR)
	{
		self->has_error = TRUE;
		return ;
	}
	module_ptr = (t_module*)module;
	module_ptr->destructor_fn = constructor.destructor_fn;
	list_add_entry(&module_ptr->node, &self->modules);
}
