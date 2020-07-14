/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:36:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 03:26:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/editor_camera_entity.h"
#include "engine/delta.h"
#include "engine/game.h"
#include "maths/maths.h"

static void	limit_scale(t_editor_camera_entity *const self)
{
	self->super.transform.scale.x = ft_fmax(self->super.transform.scale.x,
		0.025f);
	self->super.transform.scale.y = ft_fmax(self->super.transform.scale.y,
		0.025f);
	self->super.transform.scale.z = ft_fmax(self->super.transform.scale.z,
		0.025f);
	self->super.transform.scale.x = ft_fmin(self->super.transform.scale.x,
		5.0f);
	self->super.transform.scale.y = ft_fmin(self->super.transform.scale.y,
		5.0f);
	self->super.transform.scale.z = ft_fmin(self->super.transform.scale.z,
		5.0f);
}

void		editor_camera_entity_update(t_editor_camera_entity *const self)
{
	t_game	*singleton;
	float	zoom;
	float	zoom_factor;

	singleton = game_singleton();
	self->super.transform.position.y -= 6.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->up);
	self->super.transform.position.x += 6.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->right);
	self->super.transform.position.y += 6.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->down);
	self->super.transform.position.x -= 6.0f / self->super.transform.scale.x
		* get_last_delta() * input_get(&singleton->input, self->left);
	zoom = input_get(&singleton->input, self->dezoom)
		+ input_get(&singleton->input, self->zoom);
	if (zoom != 0.0f)
	{
		zoom_factor = 1.0f;
		zoom_factor += ((zoom > 0.0f) ? 0.1f : -0.1f)
			* get_last_delta() * 30.0f;
		self->super.transform.scale.x *= zoom_factor;
		self->super.transform.scale.y *= zoom_factor;
		self->super.transform.scale.z *= zoom_factor;
	}
	limit_scale(self);
}
