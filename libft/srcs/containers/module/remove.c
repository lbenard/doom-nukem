/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:32:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:03:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/module.h"

void	module_remove(t_module *const self, const void *const module_ref)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_module_node	*node;

	pos = &self->modules;
	next = pos->next;
	while ((pos = next) != &self->modules)
	{
		next = next->next;
		node = (t_module_node*)pos;
		if (node->object == module_ref)
		{
			list_del_entry(pos);
			destroy_module_node(node);
			free(node);
			break ;
		}
	}
}
