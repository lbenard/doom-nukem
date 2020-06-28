/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stick_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:46:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:24:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_event	ft_stick_event(int joystick,
					int stick,
					float dead_zone,
					int flags)
{
	t_input_event	ret;

	ret.id = 0;
	ret.code = stick;
	ret.type = STICK;
	ret.invert = flags & INVERT_INPUT;
	ret.stick.joystick = joystick;
	ret.stick.dead_zone = dead_zone;
	ret.stick.negative = flags & STICK_NEGATIVE;
	ret.stick.positive = flags & STICK_POSITIVE;
	return (ret);
}
