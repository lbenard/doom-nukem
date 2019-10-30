/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_smodule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:54:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:57:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

void	module_remove_smodule(t_module *const self,
			const void *const module_ref)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_smodule		*module;

	pos = &self->smodules;
	next = pos->next;
	while ((pos = next) != &self->smodules)
	{
		next = next->next;
		module = (t_smodule*)pos;
		if (module->module_ref == module_ref)
		{
			list_del_entry(pos);
			free_smodule(module);
			break ;
		}
	}
}
