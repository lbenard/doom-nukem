/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/25 01:07:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
#include "engine/game.h"
#include "engine/delta.h"

static t_vec3f	move(const t_map *const map, t_vec3f pos, t_vec3f vel)
{
	float		box_size;
	t_corners	box_corners;
	t_vec2f		next_position;

	box_size = 0.1;
	box_corners = ft_corners(0, 0, 0, 0);
	next_position = ft_vec2f(pos.x + vel.x, pos.y + vel.y);
	if (is_colliding(map, next_position, box_size, &box_corners))
	{
		if (is_vertical_collide(box_corners))
			return (ft_vec3f(0, vel.y, vel.z));
		else if (is_horizontal_collide(box_corners))
			return (ft_vec3f(vel.x, 0, vel.z));
		else if (is_corner_collide(box_corners, &vel))
			return (vel);
		else
			return (ft_vec3f(0.0f, 0.0f, 0.0f));
	}
	return (vel);
}

static void		orientation(t_player_entity *const self, t_vec3f *rotation)
{
	float x_axis;

	x_axis = input_get(&game_singleton()->input, self->camera_down)
		+ input_get(&game_singleton()->input, self->camera_up);
	if (x_axis == 0.0f)
		self->super.transform.rotation.x = 0.0f;
	else
	{
		self->super.transform.rotation.x += x_axis * get_last_delta() * 200.0f;
		if (self->super.transform.rotation.x > 200.0f)
			self->super.transform.rotation.x = 200.0f;
		if (self->super.transform.rotation.x < -200.0f)
			self->super.transform.rotation.x = -200.0f;
	}
	rotation->y -= input_get(&game_singleton()->input, self->turn_left)
		* 2.0f * get_last_delta();
	rotation->y += input_get(&game_singleton()->input, self->turn_right)
		* 2.0f * get_last_delta();
}

static void		wasd(t_player_entity *const self,
					t_vec3f *transform,
					t_vec3f rotation)
{
	t_vec2f	rotation_trigonometry;
	float	w;
	float	a;
	float	s;
	float	d;

	w = input_get(&game_singleton()->input, self->forward);
	a = input_get(&game_singleton()->input, self->left);
	s = input_get(&game_singleton()->input, self->backward);
	d = input_get(&game_singleton()->input, self->right);
	rotation_trigonometry = ft_vec2f(cos(rotation.y), sin(rotation.y));
	transform->x += rotation_trigonometry.x * w;
	transform->y += rotation_trigonometry.y * w;
	transform->x += rotation_trigonometry.y * a;
	transform->y -= rotation_trigonometry.x * a;
	transform->x -= rotation_trigonometry.x * s;
	transform->y -= rotation_trigonometry.y * s;
	transform->x -= rotation_trigonometry.y * d;
	transform->y += rotation_trigonometry.x * d;
}

void			player_entity_update(t_player_entity *const self)
{
	t_vec3f	velocity;

	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	orientation(self, &self->super.transform.rotation);
	wasd(self, &velocity, self->super.transform.rotation);
	velocity = vec3f_scalar(velocity, get_last_delta());
	velocity = vec3f_scalar(velocity, self->speed);
	if (input_get(&game_singleton()->input, self->sprint))
		velocity = vec3f_scalar(velocity, 2.0f);
	velocity = move(self->map_ref, self->super.transform.position, velocity);
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
