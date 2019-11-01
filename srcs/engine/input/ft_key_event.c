/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:36:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 16:22:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_event	ft_key_event(int input, int flags)
{
	t_input_event	ret;

	ret.id = 0;
	ret.code = input;
	ret.type = KEY;
	ret.invert = flags & INVERT_INPUT;
	ret.key.hold = flags & KEY_HOLD;
	return (ret);
}
