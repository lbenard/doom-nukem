/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:27:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"

void	destroy_module(t_module *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_smodule	*smodule;
	t_hmodule	*hmodule;

	pos = &self->smodules;
	next = pos->next;
	while ((pos = next) != &self->smodules)
	{
		next = next->next;
		smodule = (t_smodule*)pos;
		smodule->descriptor.destroy_fn(smodule->module_ref);
		free(smodule);
	}
	pos = &self->hmodules;
	next = pos->next;
	while ((pos = next) != &self->hmodules)
	{
		next = next->next;
		hmodule = (t_hmodule*)pos;
		hmodule->descriptor.free_fn(*hmodule->module_ref);
		free(hmodule);
	}
}
