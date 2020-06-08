/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:08:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"
#include "maths/maths.h"
#include "maths/vec2i.h"

t_ray	cast(const t_map *const map,
			const t_vec2f pos,
			const t_vec2f dir)
{
	t_vec2i	ray_pos;
	t_vec2f	origin_dist;
	t_vec2f	delta_dist;
	t_vec2i	step;
	t_u8	side;
	t_bool	hit;
	float	wall;
	float	distance;
	t_ray	result;

	delta_dist = ft_vec2f(fabs(1.0f / dir.x), fabs(1.0f / dir.y));
	ray_pos = ft_vec2i((int)pos.x, (int)pos.y);
	if (dir.x < 0.0f)
	{
		step.x = -1;
		origin_dist.x = (pos.x - ray_pos.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		origin_dist.x = (ray_pos.x + 1.0f - pos.x) * delta_dist.x;
	}
	if (dir.y < 0.0f)
	{
		step.y = -1;
		origin_dist.y = (pos.y - ray_pos.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		origin_dist.y = (ray_pos.y + 1.0f - pos.y) * delta_dist.y;
	}
	hit = FALSE;
	while (!hit)
	{
		if (origin_dist.x < origin_dist.y)
		{
			origin_dist.x += delta_dist.x;
			ray_pos.x += step.x;
			side = 0;
		}
		else
		{
			origin_dist.y += delta_dist.y;
			ray_pos.y += step.y;
			side = 1;
		}
		hit = !!map->map[ray_pos.y * map->size.x + ray_pos.x].north_texture_ref;
	}
	if (side == 0)
		distance = (ray_pos.x - pos.x + (1.0f - step.x) / 2.0f) / dir.x;
	else
		distance = (ray_pos.y - pos.y + (1.0f - step.y) / 2.0f) / dir.y;
	if (side == 0)
		wall = pos.y + distance * dir.y;
	else
		wall = pos.x + distance * dir.x;
	result.hit = ft_vec2f(ray_pos.x, ray_pos.y);
	result.perpendicular_distance = distance;
	result.texture_ratio = wall - (int)wall;
	return (result);
}

static t_rgba	color(t_image *fallback_texture,
					const t_wall *const wall,
					float distance,
					float horizontal,
					float vertical)
{
	t_rgba			*texture;
	const t_image	*used_texture;
	t_rgba			ret;

	if (wall->north_texture_ref)
		used_texture = wall->north_texture_ref;
	else
		used_texture = fallback_texture;
	texture = (t_rgba*)sfImage_getPixelsPtr(used_texture->image);
	ret.integer = texture[(int)(horizontal * used_texture->size.x)
		+ (int)(vertical * used_texture->size.y) * used_texture->size.x].integer;
	ret.c.r /= (distance / 3.0f) + 1;
	ret.c.g /= (distance / 3.0f) + 1;
	ret.c.b /= (distance / 3.0f) + 1;
	return (ret);
}

static void	floor_raycasting(t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;

	i.y = target->size.y / 2 + 1;
	while (i.y < target->size.y)
	{
		float rayDirX0 = dir.x - plane.x;
		float rayDirY0 = dir.y - plane.y;
		float rayDirX1 = dir.x + plane.x;
		float rayDirY1 = dir.y + plane.y;

		int p = i.y - target->size.y / 2;

		float posZ = 0.5 * target->size.y;
		float rowDistance = posZ / p;

		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / target->size.x;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / target->size.x;

		float floorX = self->player_ref->super.transform.position.x
			+ rowDistance * rayDirX0;
		float floorY = self->player_ref->super.transform.position.y
			+ rowDistance * rayDirY0;
		i.x = 0;
		while (i.x < target->size.x)
		{
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			int tx = (int)(self->texture.size.x * (floorX - cellX)) & (self->texture.size.x - 1);
			int ty = (int)(self->texture.size.y * (floorY - cellY)) & (self->texture.size.y - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			t_rgba color;

			color = ((t_rgba*)sfImage_getPixelsPtr(self->texture.image))[self->texture.size.x * ty + tx];
			((t_rgba*)target->frame.array)[i.y * target->size.x + i.x] = color;
			((t_rgba*)target->frame.array)[(target->size.y - i.y - 1) * target->size.x + i.x] = color;

			i.x++;
		}
		i.y++;
	}
}

static void	walls_raycasting(t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;
	size_t	size;
	ssize_t	start_y;
	ssize_t	end_y;
	float	camera_x;

	i.x = 0;
	while (i.x < target->size.x)
	{
		camera_x = 2.0f * i.x / (float)target->size.x - 1;
		t_ray ray = cast(
			&self->map,
			ft_vec2f(
				self->player_ref->super.transform.position.x,
				self->player_ref->super.transform.position.y),
			ft_vec2f(dir.x + plane.x * camera_x,
			dir.y + plane.y * camera_x));
		size = target->size.y
			/ ray.perpendicular_distance;
		start_y = (ssize_t)(target->size.y - size) / 2;
		end_y = start_y + size;
		i.y = (size_t)ft_ssmax(start_y, 0);;
		while ((ssize_t)i.y < end_y && i.y < target->size.y)
		{
			((t_u32*)target->frame.array)[target->size.x * i.y + i.x] =
				color(
					&self->texture,
					&self->map.map[(int)ray.hit.y * self->map.size.x + (int)ray.hit.x],
					ray.perpendicular_distance,
					ray.texture_ratio,
					inverse_lerp(start_y, end_y, i.y)).integer;
			i.y++;
		}
		i.x++;
	}
}

void		raycasting_scene_render(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_vec2f	dir;
	t_vec2f	plane;

	dir.x = cos(self->player_ref->super.transform.rotation.y);
	dir.y = sin(self->player_ref->super.transform.rotation.y);
	plane.x = -sin(self->player_ref->super.transform.rotation.y) * tan(self->fov / 2.0f);
	plane.y = cos(self->player_ref->super.transform.rotation.y) * tan(self->fov / 2.0f);
	floor_raycasting(self, fb, dir, plane);
	walls_raycasting(self, fb, dir, plane);
}