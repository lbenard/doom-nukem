/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_skip_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:47:44 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 21:43:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/script_scene.h"
#include "engine/error.h"

static void		skip(t_script_scene *const self, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed)
		self->skip = TRUE;
	if (event->type == sfEvtMouseWheelScrolled)
		self->speed = 4.0f;
}

t_callback_node	*new_skip_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(skip, NULL)))
	{
		return (throw_error_str("new_skip_event()",
			"failed to create new skip event"));
	}
	return (node);
}
