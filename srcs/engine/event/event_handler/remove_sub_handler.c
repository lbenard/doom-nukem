/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_sub_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:27:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:52:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

void	event_handler_remove_sub_handler(t_event_handler *const self,
			t_event_handler *const sub_handler)
{
	t_list_head		*list;

	list = &self->childs;
	while ((list = list->next) != &self->childs)
	{
		if (sub_handler == (t_event_handler*)list)
		{
			list_del_entry(list);
			break ;
		}
	}
}
