/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_event_update_event.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:13:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 20:41:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "engine/error.h"
#include "maths/maths.h"

static float	update_event(const t_input_event *const event,
					const sfEvent *const sf_event)
{
	int	multiplier;

	multiplier = (event->invert) ? -1 : 1;
	if (event->type == KEY && !event->key.hold)
	{
		if (sf_event->type == sfEvtKeyPressed
			&& sf_event->key.code == event->code)
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (event->type == MOUSE && !event->mouse.hold)
	{
		if (sfMouse_isButtonPressed(event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	return (0.0f);
}

static void		update_set(t_input_set *const set,
					t_vector *const events,
					const sfEvent *const sf_event)
{
	size_t			i;
	size_t			events_size;
	t_input_event	*event;
	float			result;

	i = 0;
	result = set->value;
	events_size = events->size / sizeof(t_input_event);
	while (i < events_size)
	{
		event = (t_input_event*)events->data + i;
		if (event->id == set->id)
			result += update_event(event, sf_event);
		i++;
	}
	set->value = ft_fmin(ft_fmax(result, -1.0f), 1.0f);
}

static void		event_update(t_input *const self, const sfEvent *const sf_event)
{
	size_t		i;
	size_t		table_size;
	t_input_set	*set;

	i = 0;
	table_size = self->table.size / sizeof(t_input_set);
	while (i < table_size)
	{
		set = (t_input_set*)self->table.data + i;
		update_set(set, &self->events, sf_event);
		i++;
	}
}

t_callback_node	*new_event_update_event(void)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(event_update, NULL)))
	{
		return (throw_error_str("new_event_update_event()",
			"failed to create new event update event"));
	}
	return (node);
}
