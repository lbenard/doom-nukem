/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:58:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:53:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

t_constructor	event_handler(void *const object)
{
	static	t_event_handler_args	args;

	args.object = object;
	return (ft_constructor(init_event_handler,
		destroy_event_handler,
		sizeof(t_event_handler),
		&args));
}
