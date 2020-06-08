/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:02:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 19:55:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"
#include "containers/list.h"

void	destroy_event_handler(t_event_handler *self)
{
	list_foreach(&self->callbacks,
		__builtin_offsetof(t_callback_node, node),
		free_callback_node);
}
