/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:12:46 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 18:53:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "engine/controller.h"
#include "maths/maths.h"

static float	stick_input(const t_input_event *const event)
{
	float	value;
	float	perpendicular;

	value = sfJoystick_getAxisPosition(event->stick.joystick, event->code);
	perpendicular = sfJoystick_getAxisPosition(event->stick.joystick,
		xbox_perpendicular_axis(event->code));
	if (ft_fabs(value) <= ft_fabs(event->stick.dead_zone) &&
		ft_fabs(perpendicular) <= ft_fabs(event->stick.dead_zone))
		return (0.0f);
	if (event->stick.positive && event->stick.negative)
		return (value / 100.0f);
	if (event->stick.negative && value >= 0.0f)
		return (0.0f);
	if (event->stick.positive && value <= 0.0f)
		return (0.0f);
	return (value / 100.0f);
}

static float	update_event(const t_input_event *const event)
{
	int	multiplier;

	multiplier = (event->invert) ? -1 : 1;
	if (event->type == KEY)
	{
		if (sfKeyboard_isKeyPressed(event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (event->type == MOUSE)
	{
		if (sfMouse_isButtonPressed(event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	return (0.0f);
}

static float	update_event(const t_input_event *const event)
{
	int	multiplier;

	multiplier = (event->invert) ? -1 : 1;
	if (event->type == KEY)
	{
		if (sfKeyboard_isKeyPressed(event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (event->type == MOUSE)
	{
		if (sfMouse_isButtonPressed(event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (STICK_COMPATIBILITY && event->type == BUTTON)
	{
		if (sfJoystick_isButtonPressed(event->button.joystick, event->code))
			return (1.0f * multiplier);
		return (0.0f);
	}
	if (STICK_COMPATIBILITY && event->type == STICK)
		return (stick_input(event) * multiplier);
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
