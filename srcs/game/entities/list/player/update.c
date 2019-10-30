/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:00:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
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

static void		orientation(t_vec3f *rotation)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		rotation->y -= 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		rotation->y += 2.0f * get_last_delta();
}

static void		wasd(t_vec3f *transform, t_vec3f rotation)
{
	t_vec2f	rotation_trigonometry;

	rotation_trigonometry = ft_vec2f(cos(rotation.y), sin(rotation.y));
	if (sfKeyboard_isKeyPressed(sfKeyW) || sfKeyboard_isKeyPressed(sfKeyUp))
	{
		transform->x += rotation_trigonometry.x;
		transform->y += rotation_trigonometry.y;
	}
	if (sfKeyboard_isKeyPressed(sfKeyA))
	{
		transform->x += rotation_trigonometry.y;
		transform->y -= rotation_trigonometry.x;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
	{
		transform->x -= rotation_trigonometry.x;
		transform->y -= rotation_trigonometry.y;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		transform->x -= rotation_trigonometry.y;
		transform->y += rotation_trigonometry.x;
	}
	*transform = vec3f_normalize(*transform);
}

void			player_entity_update(t_player_entity *const self)
{
	t_vec3f	velocity;

	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	orientation(&self->super.transform.rotation);
	wasd(&velocity, self->super.transform.rotation);
	velocity = vec3f_scalar(velocity, get_last_delta());
	velocity = vec3f_scalar(velocity, self->speed);
	if (sfKeyboard_isKeyPressed(sfKeyLShift))
		velocity = vec3f_scalar(velocity, 2.0f);
	velocity = move(self->map_ref, self->super.transform.position, velocity);
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
