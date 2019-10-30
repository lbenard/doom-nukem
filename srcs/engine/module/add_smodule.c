/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_smodule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:54:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/11 16:58:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	module_add_smodule(t_module *const self,
			const t_smodule_factory factory,
			void *const module)
{
	t_smodule	*smodule;
	t_result	result;

	if (self->has_error == TRUE)
		return ;
	if (!(smodule = new_smodule(module, factory.descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("module_add_smodule()",
			"cannot allocate stack module node");
		return ;
	}
	if (factory.args)
		result = factory.descriptor.init_fn(module, factory.args);
	else
		result = factory.descriptor.init_fn(module);
	if (result == ERROR)
	{
		free(smodule);
		self->has_error = TRUE;
		throw_error_str("module_add_smodule()",
			"failed to init stack module");
		return ;
	}
	list_add_entry(&smodule->node, &self->smodules);
}
