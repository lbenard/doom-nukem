/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:51:13 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:03:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/module.h"

void	destroy_module(t_module *const self)
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
		destroy_module_node(node);
		free(node);
	}
}