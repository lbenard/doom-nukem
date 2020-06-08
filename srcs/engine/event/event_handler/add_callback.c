/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:18:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 19:55:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"
#include "types.h"
#include "containers/list.h"

t_result	event_handler_add_callback(t_event_handler *self,
				t_callback_node *callback)
{
	if (!callback)
	{
		self->module.has_error = TRUE;
		return (ERROR);
	}
	list_add_entry(&callback->node, &self->callbacks);
	return (OK);
}
