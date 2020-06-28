/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:50:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:24:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_event	ft_button_event(int joystick, int button, int flags)
{
	t_input_event	ret;

	ret.id = 0;
	ret.code = button;
	ret.type = BUTTON;
	ret.invert = flags & INVERT_INPUT;
	ret.button.joystick = joystick;
	return (ret);
}
