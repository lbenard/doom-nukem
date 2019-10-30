/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hmodule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:54:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:57:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

void	module_remove_hmodule(t_module *const self, void **const module_ref)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_hmodule		*module;

	pos = &self->hmodules;
	next = pos->next;
	while ((pos = next) != &self->hmodules)
	{
		next = next->next;
		module = (t_hmodule*)pos;
		if (module->module_ref == module_ref)
		{
			list_del_entry(pos);
			free_hmodule(module);
			break ;
		}
	}
}
