/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpendicular_axis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:30:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 22:31:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/controller.h"

int	xbox_perpendicular_axis(int axis)
{
	if (axis == XBOX_LSTICK_X)
		return (XBOX_LSTICK_Y);
	if (axis == XBOX_RSTICK_X)
		return (XBOX_RSTICK_Y);
	if (axis == XBOX_DPAD_X)
		return (XBOX_DPAD_Y);
	return (-1);
}