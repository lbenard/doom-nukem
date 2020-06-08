/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/01 20:00:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_update(t_raycasting_scene *const self)
{
	entity_list_update(&self->super.entities);
	// self->renderer.pos =
	// 	vec3f_to_vec2f(self->player_ref->super.transform.position);
	// self->renderer.dir.x = cos(self->player_ref->super.transform.rotation.y);
	// self->renderer.dir.y = sin(self->player_ref->super.transform.rotation.y);
	// self->renderer.plane.x = -sin(self->player_ref->super.transform.rotation.y);
	// self->renderer.plane.y = cos(self->player_ref->super.transform.rotation.y);
	// if (self->player_ref->super.transform.rotation.y < M_PI)
	// 	self->player_ref->super.transform.rotation.y += 2.0f * M_PI;
	// if (self->player_ref->super.transform.rotation.y > M_PI)
	// 	self->player_ref->super.transform.rotation.y -= 2.0f * M_PI;
	// self->renderer.plane = ft_vec2f(
	// 	planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed),
	// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed));
}
