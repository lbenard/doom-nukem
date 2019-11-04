/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/04 04:05:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_update(t_raycasting_scene *const self)
{
	entity_list_update(&self->super.entities);
	// self->renderer.direction = self->player_ref->super.transform.rotation.y;
	self->renderer.pos =
		vec3f_to_vec2f(self->player_ref->super.transform.position);
	// if (self->renderer.direction < M_PI)
	// 	self->renderer.direction += 2.0f * M_PI;
	// if (self->renderer.direction > M_PI)
	// 	self->renderer.direction -= 2.0f * M_PI;
}
