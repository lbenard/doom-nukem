/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:44:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 16:22:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_event	ft_mouse_event(int input, int flags)
{
	t_input_event	ret;

	ret.id = 0;
	ret.code = input;
	ret.type = MOUSE;
	ret.invert = flags & INVERT_INPUT;
	ret.mouse.hold = flags & MOUSE_HOLD;
	return (ret);
}
