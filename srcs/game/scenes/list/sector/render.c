/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:26:55 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:29:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/sector_scene.h"
#include "maths/maths.h"

typedef struct	s_ray
{
	t_vec2f	pos;
	t_vec2f	dir;
	float	camera_angle;
}				t_ray;

typedef struct	s_cast
{
	t_vec2f	pos;
	float	dist;
	t_wall	*wall;
}				t_cast;

static t_result	cast(t_ray *const ray,
					t_cast *const result,
					const t_sector *sector)
{
	size_t	i;
	t_wall	*wall;
	float	den;
	float	t;
	float	u;

	i = 0;
	while (i < sector->wall_number)
	{
		wall = &sector->walls[i];
		den = (wall->a.x - wall->b.x) * (ray->pos.y - (ray->pos.y + ray->dir.y))
			- (wall->a.y - wall->b.y) * (ray->pos.x - (ray->pos.x + ray->dir.x));
		if (den > 0.0000001f || den < -0.0000001f) {
			t = ((wall->a.x - ray->pos.x)
				* (ray->pos.y - (ray->pos.y + ray->dir.y))
				- (wall->a.y - ray->pos.y)
				* (ray->pos.x - (ray->pos.x + ray->dir.x))) / den;
			u = -((wall->a.x - wall->b.x) * (wall->a.y - ray->pos.y)
				- (wall->a.y - wall->b.y) * (wall->a.x - ray->pos.x)) / den;
			if (t > 0 && t < 1 && u > 0) {
				result->pos.x = wall->a.x + t * (wall->b.x - wall->a.x);
				result->pos.y = wall->a.y + t * (wall->b.y - wall->a.y);
				result->wall = wall;
				t_vec2f dist = ft_vec2f(
					result->pos.x - ray->pos.x,
					result->pos.y - ray->pos.y);
				result->dist = sqrt(dist.x * dist.x + dist.y * dist.y)
					* cos(atan2(ray->dir.y, ray->dir.x) - ray->camera_angle);
				return (OK);
			}
		}
		i++;
	}
	return (ERROR);
}

static void	render_column(t_frame *const fb, t_cast *const cast, t_usize i)
{
	size_t	height;
	ssize_t	start_y;
	ssize_t	end_y;
	float	fog;

	height = fb->size.y / (cast->dist / 2.0f);
	start_y = (ssize_t)(fb->size.y - height) / 2;
	end_y = start_y + height;
	fog = (1.0f / (cast->dist / 5.0f + 1.0f));
	i.y = (size_t)ft_ssmax(start_y, 0);
	size_t	horizontal;

	if (ft_fabs(cast->wall->a.x - cast->wall->b.x)
		> ft_fabs(cast->wall->a.y - cast->wall->b.y))
		horizontal = inverse_lerp(cast->wall->a.x, cast->wall->b.x, cast->pos.x)
			* cast->wall->texture_ref->size.x;
	else
		horizontal = inverse_lerp(cast->wall->a.y, cast->wall->b.y, cast->pos.y)
			* cast->wall->texture_ref->size.x;
	while ((ssize_t)i.y < end_y && i.y < fb->size.y)
	{
		t_rgba	wall_pixel;
		size_t	vertical;

		vertical = (size_t)lerp(
			0,
			cast->wall->texture_ref->size.y,
			inverse_lerp(
				start_y,
				end_y,
				i.y));
		wall_pixel = ((t_rgba*)cast->wall->texture_ref->frame.array)
			[vertical * cast->wall->texture_ref->size.x + horizontal];
		((t_rgba*)fb->frame.array)[fb->size.x * i.y + i.x] =
			blend_add(
				ft_rgba(wall_pixel.c.r * fog,
					wall_pixel.c.g * fog,
					wall_pixel.c.b * fog,
					255),
				ft_rgba(cast->wall->color.r * fog,
					cast->wall->color.g * fog,
					cast->wall->color.b * fog,
					127));
		i.y++;
	}
}

void	sector_scene_render(t_sector_scene *const self, t_frame *const fb)
{
	float	camera_angle;
	size_t	half_plan;
	t_usize	i;
	t_cast	hit;
	t_ray	ray;
	t_vec2f	plan;
	t_vec2f	dir;

	camera_angle = (float)atan2(self->camera.direction_vector.y, self->camera.direction_vector.x);
	half_plan = fb->size.x / 2.0f;
	i.x = 0;
	frame_fill(fb, ft_rgba(20, 20, 20, 255));
	while (i.x < fb->size.x)
	{
		plan = vec2f_scalar(self->camera.plan, (float)i.x - half_plan);
		dir = ft_vec2f(self->camera.to_plan.x + plan.x, self->camera.to_plan.y + plan.y);
		ray.pos = self->camera.position;
		ray.dir = dir;
		ray.camera_angle = camera_angle;

		if (cast(&ray, &hit, self->current_sector) == OK)
			render_column(fb, &hit, i);
		i.x++;
	}
}