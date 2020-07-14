/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:58:13 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:46:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "engine/error.h"

void	input_attach(t_input *const self,
			const t_input_id id,
			t_input_event type)
{
	if (id == 0)
		return ;
	type.id = id;
	if (vector_push_back(&self->events, &type, sizeof(t_input_event)) == ERROR)
	{
		throw_error_str("input_register()",
			"failed to add event in event table");
		self->module.has_error = TRUE;
		return ;
	}
}
