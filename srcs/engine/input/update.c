/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:12:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 08:43:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "maths/maths.h"

static float	update_event(const t_input_event *const event)
{
	int		multiplier;

	multiplier = (event->invert) ? -1 : 1;
	if (event->type == KEY && event->key.hold)
	{
		if (SDL_GetKeyboardState(NULL)[event->code])
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (event->type == MOUSE && event->mouse.hold)
	{
		if (SDL_GetMouseState(NULL, NULL) & event->code)
			return (1.0f * multiplier);
		return (0.0f);
	}
	return (0.0f);
}

static void		update_set(t_input_set *const set, t_vector *const events)
{
	size_t			i;
	size_t			events_size;
	t_input_event	*event;
	float			result;

	i = 0;
	result = 0.0f;
	events_size = events->size / sizeof(t_input_event);
	while (i < events_size)
	{
		event = (t_input_event*)events->data + i;
		if (event->id == set->id)
			result += update_event(event);
		i++;
	}
	set->value = ft_fmin(ft_fmax(result, -1.0f), 1.0f);
}

void			input_update(t_input *const self)
{
	size_t		i;
	size_t		table_size;
	t_input_set	*set;

	i = 0;
	table_size = self->table.size / sizeof(t_input_set);
	while (i < table_size)
	{
		set = (t_input_set*)self->table.data + i;
		update_set(set, &self->events);
		i++;
	}
}
