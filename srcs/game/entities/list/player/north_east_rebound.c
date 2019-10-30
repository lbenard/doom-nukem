/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_east_rebound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:09:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:13:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_vec3f	north_east_rebound(const t_vec3f vel)
{
	if (vel.x > 0.0f && vel.y < 0.0f)
	{
		if (vel.x * vel.x > vel.y * vel.y)
			return (ft_vec3f(0.0f, -vel.y, vel.z));
		else
			return (ft_vec3f(-vel.x, 0.0f, vel.z));
	}
	else if (vel.x > 0.0f)
		return (ft_vec3f(0.0f, vel.y, vel.z));
	else
		return (ft_vec3f(vel.x, 0.0f, vel.z));
}
