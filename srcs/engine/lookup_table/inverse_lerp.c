/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_lerp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:11:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:27:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/lookup_table.h"

float	inverse_lerp(float v0, float v1, float value)
{
	return ((value - v0) / (v1 - v0));
}
