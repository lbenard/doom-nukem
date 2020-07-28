/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/28 23:24:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
#include "game/game.h"
#include "engine/delta.h"
#include "maths/maths.h"

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

static void		wasd(t_player_entity *const self, t_vec3f rotation)
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
	self->is_moving = ft_fabs(w + s) > 0.01f || ft_fabs(a + d) > 0.01f;
	if (self->is_moving)
	{
		rotation_trigonometry = ft_vec2f(cos(rotation.y), sin(rotation.y));
		self->velocity.x += rotation_trigonometry.x * w;
		self->velocity.y += rotation_trigonometry.y * w;
		self->velocity.x += rotation_trigonometry.y * a;
		self->velocity.y -= rotation_trigonometry.x * a;
		self->velocity.x -= rotation_trigonometry.x * s;
		self->velocity.y -= rotation_trigonometry.y * s;
		self->velocity.x -= rotation_trigonometry.y * d;
		self->velocity.y += rotation_trigonometry.x * d;
	}

}

void			player_entity_update(t_player_entity *const self)
{
	float	rot_sin;
	float	rot_cos;

	self->is_dead = self->health <= 0.0f;
	if (!self->is_dead)
	{
		orientation(self, &self->super.transform.rotation);
		wasd(self, self->super.transform.rotation);
		if (self->is_moving)
		{
			self->velocity = vec3f_scalar(self->velocity, get_last_delta());
			self->velocity = vec3f_scalar(self->velocity, self->speed);
			if (input_get(&game_singleton()->input, self->sprint))
				self->velocity = vec3f_scalar(self->velocity, 2.0f);
		}
		else
			self->velocity = vec3f_scalar(self->velocity, 0.8f);
		self->velocity = move(self->map_ref, self->super.transform.position, self->velocity);
		self->super.transform.position.x += self->velocity.x;
		self->super.transform.position.y += self->velocity.y;
		self->super.transform.position.z += self->velocity.z;
	}
	rot_sin = sin(self->super.transform.rotation.y);
	rot_cos = cos(self->super.transform.rotation.y);
	self->dir = ft_vec2f(rot_cos, rot_sin);
	self->plane = vec2f_scalar(ft_vec2f(-rot_sin, rot_cos), self->fov);
}
