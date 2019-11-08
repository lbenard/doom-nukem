/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_module_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:00:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:02:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/module.h"

t_result	init_module_node(t_module_node *const self,
				void *const object,
				void (*destructor_fn)())
{
	init_list_head(&self->node);
	self->object = object;
	self->destructor_fn = destructor_fn;
	return (OK);
}