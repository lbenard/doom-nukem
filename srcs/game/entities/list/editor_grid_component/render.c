/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:57:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/20 01:47:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_grid_component_entity.h"
#include "engine/render_utils.h"
#include <stdio.h>

static void	render_columns(t_editor_grid_component_entity *const self,
				t_frame *const frame,
				t_editor_camera_entity *const camera)
{
	float	camera_start;
	float	camera_end;
	float	x;
	int		sign;

	camera_start = camera->super.transform.position.x * self->unit_size
		* camera->super.transform.scale.x - frame->size.x / 2.0f;
	camera_end = camera->super.transform.position.x * self->unit_size
		* camera->super.transform.scale.x + frame->size.x / 2.0f;
	sign = (camera_start >= 0) * 2 - 1;
	x = 0;
	if (sign == 1)
		while (x < camera_start)
			x += self->unit_size * camera->super.transform.scale.x;
	else
		while (x > camera_start)
			x -= self->unit_size * camera->super.transform.scale.x;
	while (x < camera_end)
	{
		render_column(frame, ft_usize((size_t)(x - camera_start), 0),
			frame->size.y, (x >= -0.0001f && x <= 0.0001f)
				? ft_rgba(255, 255, 255, 255) : ft_rgba_rgb(self->super.color));
		x += self->unit_size * camera->super.transform.scale.x;
	}
}

static void	render_rows(t_editor_grid_component_entity *const self,
				t_frame *const frame,
				t_editor_camera_entity *const camera)
{
	float	camera_start;
	float	camera_end;
	float	y;
	int		sign;

	camera_start = camera->super.transform.position.y * self->unit_size
		* camera->super.transform.scale.x - frame->size.y / 2.0f;
	camera_end = camera->super.transform.position.y * self->unit_size
		* camera->super.transform.scale.x + frame->size.y / 2.0f;
	sign = (camera_start >= 0) * 2 - 1;
	y = 0;
	if (sign == 1)
		while (y < camera_start)
			y += self->unit_size * camera->super.transform.scale.x;
	else
		while (y > camera_start)
			y -= self->unit_size * camera->super.transform.scale.x;
	while (y < camera_end)
	{
		render_row(frame, ft_usize(0, (size_t)(y - camera_start)),
			frame->size.x, (y >= -0.0001f && y <= 0.0001f)
				? ft_rgba(255, 255, 255, 255) : ft_rgba_rgb(self->super.color));
		y += self->unit_size * camera->super.transform.scale.x;
	}
}

void		editor_grid_component_entity_render(
				t_editor_component_entity *const self,
				t_editor_camera_entity *const camera,
				t_frame	*const frame)
{
	render_columns((t_editor_grid_component_entity*)self, frame, camera);
	render_rows((t_editor_grid_component_entity*)self, frame, camera);
}