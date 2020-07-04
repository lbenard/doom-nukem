/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/04 22:55:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"
#include "maths/maths.h"

static t_rgba	color(const t_wall *const wall,
					float distance,
					float horizontal,
					float vertical)
{
	t_rgba			*texture;
	t_rgba			ret;

	texture = (t_rgba*)sfImage_getPixelsPtr(wall->north_texture_ref->image);
	ret.integer = texture[(int)(horizontal * wall->north_texture_ref->size.x)
		+ (int)(vertical * wall->north_texture_ref->size.y) * wall->north_texture_ref->size.x].integer;
	ret.c.r /= (distance / 3.0f) + 1;
	ret.c.g /= (distance / 3.0f) + 1;
	ret.c.b /= (distance / 3.0f) + 1;
	return (ret);
}

#include <stdio.h>

static void	ceiling_raycasting(t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	floor;
	t_vec2i	t;
	float	distance;

	i.y = target->size.y / 2 - self->player_ref->super.transform.rotation.x;
	while (i.y < target->size.y)
	{
		distance = (target->size.y / 2.0f)
			/ (i.y + self->player_ref->super.transform.rotation.x
			- target->size.y / 2.0f);
		floor.x = self->player_ref->super.transform.position.x + distance
			* (dir.x - plane.x);
		floor.y = self->player_ref->super.transform.position.y + distance
			* (dir.y - plane.y);
		i.x = 0;
		while (i.x < target->size.x)
		{
			t.x = (int)(self->texture.size.x * (floor.x - (int)(floor.x)))
				& (self->texture.size.x - 1);
			t.y = (int)(self->texture.size.y * (floor.y - (int)(floor.y)))
				& (self->texture.size.y - 1);
			floor.x += distance * (dir.x + plane.x - (dir.x - plane.x))
				/ target->size.x;
			floor.y += distance * (dir.y + plane.y - (dir.y - plane.y))
				/ target->size.x;
			target->pixels[(target->size.y - i.y - 1) * target->size.x + i.x] =
				self->texture.pixels[self->texture.size.x * t.y + t.x];
			i.x++;
		}
		i.y++;
	}
}

static void	floor_raycasting(t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	floor;
	t_vec2i	t;
	float	distance;

	i.y = target->size.y / 2 + self->player_ref->super.transform.rotation.x;
	while (i.y < target->size.y)
	{
		distance = (target->size.y / 2.0f)
			/ (i.y - self->player_ref->super.transform.rotation.x
			- target->size.y / 2.0f);
		floor.x = self->player_ref->super.transform.position.x + distance
			* (dir.x - plane.x);
		floor.y = self->player_ref->super.transform.position.y + distance
			* (dir.y - plane.y);
		i.x = 0;
		while (i.x < target->size.x)
		{
			t.x = (int)(self->texture.size.x * (floor.x - (int)(floor.x)))
				& (self->texture.size.x - 1);
			t.y = (int)(self->texture.size.y * (floor.y - (int)(floor.y)))
				& (self->texture.size.y - 1);
			floor.x += distance * (dir.x + plane.x - (dir.x - plane.x))
				/ target->size.x;
			floor.y += distance * (dir.y + plane.y - (dir.y - plane.y))
				/ target->size.x;
			target->pixels[i.y * target->size.x + i.x] =
				self->texture.pixels[self->texture.size.x * t.y + t.x];
			i.x++;
		}
		i.y++;
	}
}

static void	walls_raycasting(t_raycasting_scene *const self,
				t_frame *const target)
{
	t_usize	i;
	size_t	size;
	ssize_t	start_y;
	ssize_t	end_y;
	t_ray	*ray;

	i.x = 0;
	while (i.x < target->size.x)
	{
		ray = &((t_ray*)self->zbuffer.array)[i.x];
		size = target->size.x / ray->perpendicular_distance
			* ((float)target->size.y / target->size.x);
		start_y = (ssize_t)(target->size.y - size) / 2
			+ self->player_ref->super.transform.rotation.x;
		end_y = start_y + size;
		i.y = (size_t)ft_ssmax(start_y, 0);
		while ((ssize_t)i.y < end_y && i.y < target->size.y)
		{
			target->pixels[target->size.x * i.y + i.x] = color(
				&self->map.map[(int)(ray->hit.y * self->map.size.x + ray->hit.x)],
					ray->perpendicular_distance, ray->horizontal_ratio,
					inverse_lerp(start_y, end_y, i.y));
			i.y++;
		}
		i.x++;
	}
}

static void	zbuffer(t_raycasting_scene *const self,
				const t_vec2f dir,
				const t_vec2f plane)
{
	size_t	i;
	size_t	length;
	float	camera_x;
	t_ray	*buffer;

	length = self->zbuffer.size / sizeof(t_ray);
	buffer = (t_ray*)self->zbuffer.array;
	i = 0;
	while (i < length)
	{
		camera_x = 2.0f * i / (float)length - 1;
		buffer[i] = cast(&self->map,
			ft_vec2f(self->player_ref->super.transform.position.x,
				self->player_ref->super.transform.position.y),
			ft_vec2f(dir.x + plane.x * camera_x, dir.y + plane.y * camera_x));
		i++;
	}
}

void		sprites(t_raycasting_scene *const self,
				t_frame *const fb,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_usize			i;
	t_ray			*zbuffer;
	t_usize			sprite_px;

	zbuffer = (t_ray*)self->zbuffer.array;
	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		
		t_vec2d	sprite_pos;
		sprite_pos.x = sprite->super.transform.position.x
			- self->player_ref->super.transform.position.x;
		sprite_pos.y = sprite->super.transform.position.y
			- self->player_ref->super.transform.position.y;
		
		double inv_det = 1.0 / (plane.x * dir.y - dir.x * plane.y);

		t_vec2d	transform;
		transform.x = inv_det * (dir.y * sprite_pos.x - dir.x * sprite_pos.y);
		transform.y = inv_det * (-plane.y * sprite_pos.x + plane.x * sprite_pos.y);
		if (transform.y <= 0)
			continue ;

		int	sprite_screen_x = (int)((fb->size.x / 2) * (1 + transform.x / transform.y));

		int	sprite_height = ft_abs((int)(fb->size.y / transform.y));
		int	draw_start_y = fb->size.y / 2 - sprite_height / 2
			+ (int)self->player_ref->super.transform.rotation.x;
		int draw_end_y = fb->size.y / 2 + sprite_height / 2
			+ (int)self->player_ref->super.transform.rotation.x;

		int	sprite_width = ft_abs((int)(fb->size.y / transform.y));
		int	draw_start_x = sprite_screen_x - sprite_width / 2;
		int	draw_end_x = sprite_screen_x + sprite_width / 2;
		i.x = (size_t)ft_ssmax(draw_start_x, 0);
		while ((ssize_t)i.x < draw_end_x && i.x < fb->size.x)
		{
			if (transform.y >= zbuffer[i.x].perpendicular_distance)
			{
				i.x++;
				continue ;
			}
			sprite_px.x = inverse_lerp(draw_start_x, draw_end_x, i.x)
				* sprite->texture.size.x;
			i.y = (size_t)ft_ssmax(draw_start_y, 0);
			while ((ssize_t)i.y < draw_end_y && i.y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(draw_start_y, draw_end_y, i.y)
					* sprite->texture.size.y;
				fb->pixels[i.y * fb->size.x + i.x] =
					blend_add(fb->pixels[i.y * fb->size.x + i.x],
					sprite->texture.pixels[sprite_px.y * sprite->texture.size.x + sprite_px.x]);
				i.y++;
			}
			i.x++;
		}
	}
}

void		raycasting_scene_render(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_vec2f	dir;
	t_vec2f	plane;
	float	fov;
	float	rot_sin;
	float	rot_cos;

	fov = tan(self->fov / 2.0f);
	rot_sin = sin(self->player_ref->super.transform.rotation.y);
	rot_cos = cos(self->player_ref->super.transform.rotation.y);
	dir = ft_vec2f(rot_cos, rot_sin);
	plane = vec2f_scalar(ft_vec2f(-rot_sin, rot_cos), fov);
	zbuffer(self, dir, plane);
	floor_raycasting(self, fb, dir, plane);
	ceiling_raycasting(self, fb, dir, plane);
	walls_raycasting(self, fb);
	sprites(self, fb, dir, plane);
}
