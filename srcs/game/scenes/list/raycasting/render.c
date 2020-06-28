/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/25 01:41:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"
#include "maths/maths.h"

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
	t_vec2f	left_ray;
	t_vec2f	right_ray;
	t_vec2f	floor;
	t_vec2i	t;
	float	distance;

	i.y = target->size.y / 2;
	while (i.y < target->size.y)
	{
		left_ray.x = dir.x - plane.x;
		left_ray.y = dir.y - plane.y;
		right_ray.x = dir.x + plane.x;
		right_ray.y = dir.y + plane.y;
		distance = (target->size.y / 2.0f) / (i.y + self->player_ref->super.transform.rotation.x - target->size.y / 2.0f);
		floor.x = self->player_ref->super.transform.position.x + distance
			* left_ray.x;
		floor.y = self->player_ref->super.transform.position.y + distance
			* left_ray.y;
		i.x = 0;
		while (i.x < target->size.x)
		{
			t.x = (int)(self->texture.size.x * (floor.x - (int)(floor.x)))
				& (self->texture.size.x - 1);
			t.y = (int)(self->texture.size.y * (floor.y - (int)(floor.y)))
				& (self->texture.size.y - 1);
			floor.x += distance * (right_ray.x - left_ray.x) / target->size.x;
			floor.y += distance * (right_ray.y - left_ray.y) / target->size.x;
			t_rgba color = ((t_rgba*)sfImage_getPixelsPtr(self->texture.image))[self->texture.size.x * t.y + t.x];
			// if (i.y > target->size.y / 2 - self->player_ref->super.transform.rotation.x)
				((t_rgba*)target->frame.array)[(target->size.y - i.y - 1) * target->size.x + i.x] = color;
				((t_rgba*)target->frame.array)[i.y * target->size.x + i.x] = color;
			i.x++;
		}
		i.y++;
	}
}

static void	glass_raycasting(t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	left_ray;
	t_vec2f	right_ray;
	t_vec2f	floor;
	t_vec2i	t;
	float	distance;

	i.y = target->size.y / 2;
	while (i.y < target->size.y)
	{
		left_ray.x = dir.x - plane.x;
		left_ray.y = dir.y - plane.y;
		right_ray.x = dir.x + plane.x;
		right_ray.y = dir.y + plane.y;
		distance = (target->size.y / 2.0f) / (i.y - target->size.y / 2.0f);
		floor.x = self->player_ref->super.transform.position.x + distance
			* left_ray.x;
		floor.y = self->player_ref->super.transform.position.y + distance
			* left_ray.y;
		i.x = 0;
		while (i.x < target->size.x)
		{
			t.x = (int)(self->texture.size.x * (floor.x - (int)(floor.x)))
				& (self->texture.size.x - 1);
			t.y = (int)(self->texture.size.y * (floor.y - (int)(floor.y)))
				& (self->texture.size.y - 1);
			floor.x += distance * (right_ray.x - left_ray.x) / target->size.x;
			floor.y += distance * (right_ray.y - left_ray.y) / target->size.x;
			t_rgba color = ((t_rgba*)sfImage_getPixelsPtr(self->texture.image))[self->texture.size.x * t.y + t.x];
			color.c.a = 100;

			((t_rgba*)target->frame.array)[i.y * target->size.x + i.x] = blend_add(((t_rgba*)target->frame.array)[i.y * target->size.x + i.x], color);
			((t_rgba*)target->frame.array)[(target->size.y - i.y - 1) * target->size.x + i.x] = blend_add(((t_rgba*)target->frame.array)[(target->size.y - i.y - 1) * target->size.x + i.x], color);
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
		size = target->size.x / ray->perpendicular_distance * ((float)target->size.y / target->size.x);
		start_y = (ssize_t)(target->size.y - size) / 2 + self->player_ref->super.transform.rotation.x;
		end_y = start_y + size;
		i.y = (size_t)ft_ssmax(start_y, 0);
		while ((ssize_t)i.y < end_y && i.y < target->size.y)
		{
			((t_rgba*)target->frame.array)[target->size.x * i.y + i.x] =
				color(&self->texture,
					&self->map.map[(int)ray->hit.y * self->map.size.x + (int)ray->hit.x],
					ray->perpendicular_distance,
					ray->horizontal_ratio,
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

#include <stdio.h>

void		sprites(t_raycasting_scene *const self,
				t_frame *const fb,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite_node;
	t_frame			*sprite_frame;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite_node = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		// sprite_frame = &sprite_node->texture;
		sprite_frame = &self->last_frame;
		t_vec3f	sprite_pos;
		sprite_pos = sprite_node->super.transform.position;
		sprite_pos.x -= self->player_ref->super.transform.position.x;
		sprite_pos.y -= self->player_ref->super.transform.position.y;

		t_vec2f	transform;
		transform.x = dir.y * sprite_pos.x - dir.x * sprite_pos.y;
		transform.y = -plane.y * sprite_pos.x + plane.x * sprite_pos.y;
		transform = vec2f_scalar(transform,
			1.0f / (plane.x * dir.y - dir.x * plane.y));

		ssize_t	sprite_screen_x = (fb->size.x / 2) * (1 + transform.x / transform.y);
		ssize_t	sprite_height = ft_abs(fb->size.y / transform.y);

		size_t	draw_start_y = ft_max(0, -sprite_height / 2 + fb->size.y / 2);
		size_t	draw_end_y = ft_min(fb->size.y - 1, sprite_height / 2 + fb->size.y / 2);

		ssize_t	sprite_width = ft_abs(fb->size.y / transform.y);
		size_t	draw_start_x = ft_max(0, -sprite_width / 2 + sprite_screen_x);
		size_t	draw_end_x = ft_min(fb->size.x - 1, sprite_width / 2 + sprite_screen_x);

		t_isize	i;

		i.x = draw_start_x;
		while (i.x < (ssize_t)draw_end_x)
		{
			size_t	tex_x = (256 * (i.x - (-sprite_width / 2 + sprite_screen_x)) * sprite_frame->size.x / sprite_width) / 256;
			if (transform.y > 0
				&& i.x > 0
				&& i.x < (ssize_t)fb->size.x
				&& transform.y < ((t_ray*)self->zbuffer.array)[i.x].perpendicular_distance)
			{
				i.y = draw_start_y;
				while (i.y < (ssize_t)draw_end_y)
				{
					ssize_t	d = i.y * 256 - sprite_frame->size.y * 128 + sprite_height * 128;
					size_t	tex_y = ((d * sprite_frame->size.y) / sprite_height) / 256;
					// printf("tex: %lu %lu\n", tex_x, tex_y);
					((t_rgba*)fb->frame.array)[i.y * fb->size.x + i.x] =
						((t_rgba*)sprite_frame->frame.array)[tex_y * sprite_frame->size.x + tex_x];
					i.y++;
				}
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
	(void)glass_raycasting;
	// glass_raycasting(self, fb, dir, plane);
	walls_raycasting(self, fb);
	frame_layer_opaque(&self->last_frame, fb, ft_isize(0, 0));
	// frame_layer(fb, &((t_sprite_entity*)self->sprite_entities.list.next)->texture, ft_isize(0, 0), blend_add);
	sprites(self, fb, dir, plane);
	// frame_layer(fb, &((t_sprite_entity*)((t_entity_node*)self->sprite_entities.list.next)->entity)->texture, ft_isize(0, 0), blend_add);
}