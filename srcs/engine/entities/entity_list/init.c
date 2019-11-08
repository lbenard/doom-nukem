/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:45:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:51:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/error.h"

t_result	init_entity_list(t_entity_list *const self)
{
	init_module(&self->module);
	if (init_vector(&self->batch) == ERROR)
	{
		return (throw_result_str("init_entity_list()",
			"failed to init entity batch"));
	}
	init_list_head(&self->list);
	return (OK);
}
