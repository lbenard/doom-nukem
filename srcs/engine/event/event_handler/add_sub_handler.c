/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:28:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:50:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

void	event_handler_add_sub_handler(t_event_handler *const self,
			t_event_handler *const sub_handler)
{
	list_add_entry(&sub_handler->node, &self->childs);
}
