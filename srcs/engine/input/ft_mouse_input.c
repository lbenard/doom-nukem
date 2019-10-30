/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:44:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 16:46:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_type	ft_mouse_input(int input, int flags)
{
	t_input_type	ret;

	ret.id = 0;
	ret.code = input;
	ret.type = MOUSE;
	ret.invert = flags & INVERT_INPUT;
	ret.mouse.hold = flags & MOUSE_HOLD;
	return (ret);
}
