/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_sub_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:27:53 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/08 20:56:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

void	event_handler_remove_sub_handler(t_event_handler *const self,
			t_event_handler *const sub_handler)
{
	t_list_head		*list;
	t_event_handler	*sub;

	list = &self->childs;
	while ((list = list->next) != &self->childs)
	{
		sub = (t_event_handler*)((t_u8*)list
			- __builtin_offsetof(t_event_handler, node));
		if (sub_handler == sub)
		{
			list_del_entry(list);
			break ;
		}
	}
}
