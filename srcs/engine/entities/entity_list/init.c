/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:45:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 15:38:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"
#include "engine/error.h"

t_result	init_entity_list(t_entity_list *const self,
				const t_entity_list_args *const args)
{
	(void)args;
	init_module(&self->module);
	if (init_vector(&self->batch) == ERROR)
	{
		return (throw_result_str("init_entity_list()",
			"failed to init entity batch"));
	}
	init_list_head(&self->list);
	return (OK);
}
