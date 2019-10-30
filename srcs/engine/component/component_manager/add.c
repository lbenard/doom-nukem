/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:34:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:16:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component.h"
#include "engine/error.h"

static size_t	size_to_fit(size_t size, const size_t fit)
{
	if (size == 0)
		size = fit;
	while (size <= fit)
		size *= 2;
	return (size);
}

t_result		component_manager_add(t_component_manager *const self,
					const t_entity_uid entity_id,
					const void *const component_args)
{
	size_t	index;

	index = self->component_size * entity_id;
	if (vector_reserve(&self->list,
			size_to_fit(self->list.capacity,
			index + self->component_size) == ERROR)
	{
		return (throw_error_str("component_manager_add()",
			"failed to reserve vector"));
	}
	if (self->component_factory.descriptor.init_fn(self->list.data + index,
		component_args) == ERROR)
	{
		return (throw_error_str("component_manager_add()",
			"failed to init new component"));
	}
	return (OK);
}