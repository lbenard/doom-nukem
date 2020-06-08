/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:26:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:28:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/sector_scene.h"
#include "engine/delta.h"
#include "engine/game.h"

void	sector_scene_update(t_sector_scene *const self)
{
	float	w;
	float	a;
	float	s;
	float	d;
	float	left_arrow;
	float	right_arrow;

	t_vec2f transform;
	transform = ft_vec2f(0.0f, 0.0f);
	if ((w = input_get(&game_singleton()->input, self->w)))
		transform.y += 1.0f;
	if ((a = input_get(&game_singleton()->input, self->a)))
		transform.x -= 1.0f;
	if ((s = input_get(&game_singleton()->input, self->s)))
		transform.y -= 1.0f;
	if ((d = input_get(&game_singleton()->input, self->d)))
		transform.x += 1.0f;
	transform = vec2f_normalize(transform);
	transform = vec2f_scalar(transform, get_last_delta());
	transform = vec2f_scalar(transform, 10.0f);
	self->camera.position.x += transform.x;
	self->camera.position.y += transform.y;
	if ((left_arrow = input_get(&game_singleton()->input, self->left_arrow)))
		self->camera.angle -= 2.0f * get_last_delta();
	if ((right_arrow = input_get(&game_singleton()->input, self->right_arrow)))
		self->camera.angle += 2.0f * get_last_delta();
	self->camera.direction_vector = ft_vec2f(
		cos(self->camera.angle),
		sin(self->camera.angle));
	self->camera.to_plan = vec2f_scalar(self->camera.direction_vector, self->camera.camera_to_plan_dist);
	self->camera.plan = ft_vec2f(self->camera.direction_vector.y, -self->camera.direction_vector.x);
}