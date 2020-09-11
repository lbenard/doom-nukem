/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 07:42:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

static void	call(t_event_handler *const self, SDL_Event *const event)
{
	t_list_head		*pos;
	t_callback_node	*node;

	pos = self->callbacks.next;
	while (pos != &self->callbacks)
	{
		node = (t_callback_node*)pos;
		if (node->params)
			node->callback(self->object, event, node->params);
		else
			node->callback(self->object, event);
		pos = pos->next;
	}
}

void		event_handler_call(t_event_handler *const self,
				SDL_Event *const event)
{
	t_list_head		*pos;
	t_event_handler	*sub_handler;

	call(self, event);
	pos = self->childs.next;
	while (pos != &self->childs)
	{
		sub_handler = (t_event_handler*)((t_u8*)pos
			- __builtin_offsetof(t_event_handler, node));
		event_handler_call(sub_handler, event);
		pos = pos->next;
	}
}
