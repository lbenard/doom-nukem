/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:14:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:52:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/event_handler.h"
#include "engine/error.h"

t_callback_node	*new_callback_node(void (*callback)(), void *const params)
{
	t_callback_node	*ret;

	if (!(ret = (t_callback_node*)malloc(sizeof(t_callback_node))))
	{
		return (throw_error_str("new_callback_node()",
			"failed to create new callback node"));
	}
	ret->callback = callback;
	ret->params = params;
	if (!init_list_head(&ret->node))
	{
		free(ret);
		return (throw_error_str("new_callback_node()",
			"failed to initalize callback list"));
	}
	return (ret);
}
