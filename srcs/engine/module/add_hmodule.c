/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hmodule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:54:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/11 16:59:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	module_add_hmodule(t_module *const self,
			const t_hmodule_factory factory,
			void **const module)
{
	t_hmodule	*hmodule;

	if (self->has_error == TRUE)
		return ;
	if (!(hmodule = new_hmodule(module, factory.descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("module_add_hmodule()",
			"cannot allocate heap module node");
		return ;
	}
	if (factory.args)
		*module = factory.descriptor.new_fn(factory.args);
	else
		*module = factory.descriptor.new_fn();
	if (!(*module))
	{
		free(hmodule);
		self->has_error = TRUE;
		throw_error_str("module_add_hmodule()",
			"failed to init heap module");
		return ;
	}
	list_add_entry(&hmodule->node, &self->hmodules);
}
