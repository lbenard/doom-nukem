/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:50:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 16:51:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_type	ft_button_input(int joystick, int button, int flags)
{
	t_input_type	ret;

	ret.id = 0;
	ret.code = button;
	ret.type = BUTTON;
	ret.invert = flags & INVERT_INPUT;
	ret.button.joystick = joystick;
	return (ret);
}