/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:17:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:14:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_component_manager(t_component_manager *const self,
				const t_component_manager_args *const args)
{
	init_module(&self->module);
	init_list_head(&self->node);
	if (init_vector(&self->list) == ERROR)
	{
		return (throw_result_str("init_component_manager()",
			"failed to init component vector"));
	}
	if (vector_reserve(args->component_size) == ERROR)
	{
		destroy_vector(&self->list);
		return (throw_error_str("init_component_manager()",
			"failed to reserve vector to component size"));
	}
	if (!(self->name = ft_strdup(args->name)))
	{
		destroy_vector(&self->list);
		return (throw_error_str("init_component_manager()",
			"failed to dup component name"));
	}
	self->uid = get_new_component_uid();
	self->is_active = TRUE;
	self->component_factory = args->component_factory;
	self->component_size = args->component_size;
	return (OK);
}