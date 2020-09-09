/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_darkness.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:05:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 11:07:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_update_darkness(t_raycasting_scene *const self)
{
	float	time;

	time = get_wall_time() - self->weapon.last_shot;
	if (time >= 0.0f && time <= 0.3f)
		self->darkness = 2.0f * (time * 3.33f);
	else
		self->darkness = 2.0f;
}
