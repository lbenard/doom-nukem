/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:17:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:52:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"
#include "types.h"

t_result	init_event_handler(t_event_handler *const self,
				const t_event_handler_args *const args)
{
	init_module(&self->module);
	if (!init_list_head(&self->callbacks))
		return (ERROR);
	*(void**)&self->object = args->object;
	init_list_head(&self->node);
	init_list_head(&self->childs);
	return (OK);
}
