/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:57:03 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 23:36:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"
#include "engine/render_utils.h"
#include "maths/maths.h"

static t_rgba	color_from_zoom(const t_vec3f zoom, const t_bool is_zero_axis)
{
	if (is_zero_axis)
		return (ft_rgba(255, 255, 255, 255));
	if (zoom.x < 0.1f)
	{
		return (ft_rgba(127, 127, 127,
			(int)lerp(255, 0, inverse_lerp(0.1f, 0.01f, zoom.x))));
	}
	return (ft_rgba(127, 127, 127, 255));
}

static float	render_helper(t_grid_component_entity *const self,
					t_editor_camera_entity *const camera,
					float camera_start)
{
	int		sign;
	float	x;

	sign = (camera_start >= 0) * 2 - 1;
	x = 0;
	if (sign == 1)
		while (x < camera_start)
			x += self->unit_size * camera->super.transform.scale.x;
	else
		while (x > camera_start)
			x -= self->unit_size * camera->super.transform.scale.x;
	return (x);
}

static void		render_columns(t_grid_component_entity *const self,
					t_frame *const frame,
					t_editor_camera_entity *const camera)
{
	float	camera_start;
	float	camera_end;
	float	x;

	camera_start = camera->super.transform.position.x * self->unit_size
		* camera->super.transform.scale.x -
		self->super.super.transform.scale.x / 2.0f;
	camera_end = camera->super.transform.position.x * self->unit_size
		* camera->super.transform.scale.x +
		self->super.super.transform.scale.x / 2.0f;
	x = render_helper(self, camera, camera_start);
	while (x < camera_end)
	{
		render_column(frame, ft_usize((size_t)(x - camera_start),
			self->super.super.transform.position.y),
			self->super.super.transform.scale.y, color_from_zoom(
				camera->super.transform.scale, (x > -0.0001f && x < 0.0001f)));
		x += self->unit_size * camera->super.transform.scale.x;
	}
}

static void		render_rows(t_grid_component_entity *const self,
					t_frame *const frame,
					t_editor_camera_entity *const camera)
{
	float	camera_start;
	float	camera_end;
	float	y;

	camera_start = camera->super.transform.position.y * self->unit_size
		* camera->super.transform.scale.x -
		self->super.super.transform.scale.y / 2.0f;
	camera_end = camera->super.transform.position.y * self->unit_size
		* camera->super.transform.scale.x +
		self->super.super.transform.scale.y / 2.0f;
	y = render_helper(self, camera, camera_start);
	while (y < camera_end)
	{
		render_row(frame, ft_usize(self->super.super.transform.position.x,
			(size_t)(y - camera_start)), self->super.super.transform.scale.x,
			color_from_zoom(camera->super.transform.scale,
				(y > -0.0001f && y < 0.0001f)));
		y += self->unit_size * camera->super.transform.scale.x;
	}
}

void			grid_component_entity_render(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame	*const frame)
{
	if (camera->super.transform.scale.x > 0.01f)
	{
		render_columns((t_grid_component_entity*)self, frame, camera);
		render_rows((t_grid_component_entity*)self, frame, camera);
	}
}
