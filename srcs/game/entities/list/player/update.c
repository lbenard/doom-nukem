/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 21:31:53 by lbenard          ###   ########.fr       */
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

static void		orientation(t_vec3f *rotation)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		rotation->y -= 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		rotation->y += 2.0f * get_last_delta();
}

#include <stdio.h>

static void		wasd(t_player_entity *const self,
					t_vec3f *transform,
					t_vec3f rotation)
{
	t_vec2f	rotation_trigonometry;
	float	w;
	float	a;
	float	s;
	float	d;

	rotation_trigonometry = ft_vec2f(cos(rotation.y), sin(rotation.y));
	w = input_get(&game_singleton()->input, self->forward);
	a = input_get(&game_singleton()->input, self->left);
	s = input_get(&game_singleton()->input, self->backward);
	d = input_get(&game_singleton()->input, self->right);
	printf("w: %f\na: %f\ns; %f\nd: %f\n", w, a, s, d);
	printf("%f\n", cos(w * M_PI / 2.0f));
	// if (input_get(&game_singleton()->input, self->forward))
	// {
	transform->x += rotation_trigonometry.x * w;// * cos(w * M_PI / 2.0f);
	transform->y += rotation_trigonometry.y * w;// * cos(w * M_PI / 2.0f);
	// }
	// if (input_get(&game_singleton()->input, self->left))
	// {
	transform->x += rotation_trigonometry.y * a;// * cos(a * M_PI / 2.0f);
	transform->y -= rotation_trigonometry.x * a;// * cos(a * M_PI / 2.0f);
	// }
	// if (input_get(&game_singleton()->input, self->backward))
	// {
	transform->x -= rotation_trigonometry.x * s;// * cos(s * M_PI / 2.0f);
	transform->y -= rotation_trigonometry.y * s;// * cos(s * M_PI / 2.0f);
	// }
	// if (input_get(&game_singleton()->input, self->right))
	// {
	transform->x -= rotation_trigonometry.y * d;// * cos(d * M_PI / 2.0f);
	transform->y += rotation_trigonometry.x * d;// * cos(d * M_PI / 2.0f);
	// }
	// *transform = vec3f_normalize(*transform);
}

void			player_entity_update(t_player_entity *const self)
{
	t_vec3f	velocity;

	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	orientation(&self->super.transform.rotation);
	wasd(self, &velocity, self->super.transform.rotation);
	printf("velocity: %f %f %f\n", velocity.x, velocity.y, velocity.z);
	velocity = vec3f_scalar(velocity, get_last_delta());
	printf("velocity: %f %f %f\n", velocity.x, velocity.y, velocity.z);
	velocity = vec3f_scalar(velocity, self->speed);
	printf("velocity: %f %f %f\n", velocity.x, velocity.y, velocity.z);
	if (input_get(&game_singleton()->input, self->sprint))
		velocity = vec3f_scalar(velocity, 2.0f);
	velocity = move(self->map_ref, self->super.transform.position, velocity);
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
