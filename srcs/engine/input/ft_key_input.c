/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:36:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 16:44:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_type	ft_key_input(int input, int flags)
{
	t_input_type	ret;

	ret.id = 0;
	ret.code = input;
	ret.type = KEY;
	ret.invert = flags & INVERT_INPUT;
	ret.key.hold = flags & KEY_HOLD;
	return (ret);
}
