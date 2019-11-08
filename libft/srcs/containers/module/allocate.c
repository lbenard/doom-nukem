/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:09:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:03:41 by lbenard          ###   ########.fr       */
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
	void	*module;

	if (!(module = malloc(constructor.module_size)))
		return (NULL);
	if (construct_module(module, constructor) == ERROR)
	{
		free(module);
		return (NULL);
	}
	return (module);
}
