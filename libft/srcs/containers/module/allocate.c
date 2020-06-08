/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:09:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 19:58:01 by lbenard          ###   ########.fr       */
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

void			*static_module_allocate(const t_constructor constructor)
{
	void		*module;
	t_module	*module_ptr;

	if (!(module = malloc(constructor.module_size)))
		return (NULL);
	if (construct_module(module, constructor) == ERROR)
	{
		free(module);
		return (NULL);
	}
	module_ptr = (t_module*)module;
	module_ptr->destructor_fn = constructor.destructor_fn;
	return (module);
}
