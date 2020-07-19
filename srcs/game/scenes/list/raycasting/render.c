/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:25:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"
#include "maths/maths.h"
#include "engine/delta.h"

static t_rgba	color(const t_raycasting_scene *const self,
					const t_ray *const ray,
					const float vertical)
{
	const t_frame	*texture;
	t_rgba			ret;

	if (ray->hit.x >= self->map.size.x || ray->hit.y >= self->map.size.y
		|| ray->hit.x < 0 || ray->hit.y < 0)
		texture = &self->floor;
	else
		texture = self->map.map[(int)ray->hit.y * self->map.size.x
			+ (int)ray->hit.x].texture_ref;
	ret = texture->pixels[(int)(ray->horizontal_ratio * texture->size.x)
		+ (int)(vertical * texture->size.y) * texture->size.x];
	ret.c.r /= (ray->perpendicular_distance / 3.0f) + 1;
	ret.c.g /= (ray->perpendicular_distance / 3.0f) + 1;
	ret.c.b /= (ray->perpendicular_distance / 3.0f) + 1;
	return (ret);
}

static void	ceiling_raycasting(const t_raycasting_scene *const self,
				t_frame *const target,
				const t_vec2f dir,
				const t_vec2f plane)
{
	t_usize	i;
	t_vec2f	floor;
	t_vec2i	t;
	float	distance;
	float	darkness_step;
	float	darkness_value;

	i.y = target->size.y / 2 - self->player_ref->super.transform.rotation.x;
	darkness_step = 1.0f / target->size.y / 2 * 5.0f;
	darkness_value = 0.0f;
	while (i.y < target->size.y)
	{
		distance = (target->size.y / 1.0f)
			/ (i.y + self->player_ref->super.transform.rotation.x
			- target->size.y / 2.0f);
		floor.x = self->player_ref->super.transform.position.x + distance
			* (dir.x - plane.x);
		floor.y = self->player_ref->super.transform.position.y + distance
			* (dir.y - plane.y);
		i.x = 0;
		while (i.x < target->size.x)
		{
			t.x = (int)(self->ceiling.size.x * (floor.x - (int)(floor.x)))
				& (self->ceiling.size.x - 1);
			t.y = (int)(self->ceiling.size.y * (floor.y - (int)(floor.y)))
				& (self->ceiling.size.y - 1);
			floor.x += distance * (dir.x + plane.x - (dir.x - plane.x))
				/ target->size.x;
			floor.y += distance * (dir.y + plane.y - (dir.y - plane.y))
				/ target->size.x;
			t_rgba	floor_color = self->ceiling.pixels[self->ceiling.size.x * t.y + t.x];
			floor_color.c.r *= ft_fmin(darkness_value, 1.0f);
			floor_color.c.g *= ft_fmin(darkness_value, 1.0f);
			floor_color.c.b *= ft_fmin(darkness_value, 1.0f);
			target->pixels[(target->size.y - i.y - 1) * target->size.x + i.x] =
				floor_color;
			i.x++;
		}
		darkness_value += darkness_step;
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
	float	darkness_step;
	float	darkness_value;

	i.y = target->size.y / 2 + self->player_ref->super.transform.rotation.x;
	darkness_step = 1.0f / target->size.y / 2 * 10.0f;
	darkness_value = 0.0f;
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
			t.x = (int)(self->floor.size.x * (floor.x - (int)(floor.x)))
				& (self->floor.size.x - 1);
			t.y = (int)(self->floor.size.y * (floor.y - (int)(floor.y)))
				& (self->floor.size.y - 1);
			floor.x += distance * (dir.x + plane.x - (dir.x - plane.x))
				/ target->size.x;
			floor.y += distance * (dir.y + plane.y - (dir.y - plane.y))
				/ target->size.x;
			t_rgba	floor_color = self->floor.pixels[self->floor.size.x * t.y + t.x];
			floor_color.c.r *= ft_fmin(darkness_value, 1.0f);
			floor_color.c.g *= ft_fmin(darkness_value, 1.0f);
			floor_color.c.b *= ft_fmin(darkness_value, 1.0f);
			target->pixels[i.y * target->size.x + i.x] = floor_color;
			i.x++;
		}
		darkness_value += darkness_step;
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
			target->pixels[target->size.x * i.y + i.x] = color(self, ray,
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
	t_frame			*sprite_texture;

	zbuffer = (t_ray*)self->zbuffer.array;
	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		sprite_texture = &sprite->texture;
		
		t_vec2d	sprite_pos;
		sprite_pos.x = sprite->super.transform.position.x
			- self->player_ref->super.transform.position.x;
		sprite_pos.y = sprite->super.transform.position.y
			- self->player_ref->super.transform.position.y;
		
		double inv_det = 1.0 / (plane.x * dir.y - dir.x * plane.y);

		t_vec2d	transform;
		transform.x = inv_det * (dir.y * sprite_pos.x - dir.x * sprite_pos.y);
		transform.y = inv_det * (-plane.y * sprite_pos.x + plane.x * sprite_pos.y);

		int	sprite_screen_x = (int)((fb->size.x / 2) * (1 + transform.x / transform.y));

		int	sprite_height = ft_abs((int)(fb->size.y / transform.y));
		int	draw_start_y = fb->size.y / 2 - sprite_height / 2
			+ (int)self->player_ref->super.transform.rotation.x;
		int draw_end_y = fb->size.y / 2 + sprite_height / 2
			+ (int)self->player_ref->super.transform.rotation.x;
		sprite->last_start_y = draw_start_y;
		sprite->last_end_y = draw_end_y;

		int	sprite_width = ft_abs((int)(fb->size.y / transform.y));
		int	draw_start_x = sprite_screen_x - sprite_width / 2;
		int	draw_end_x = sprite_screen_x + sprite_width / 2;
		sprite->last_start_x = draw_start_x;
		sprite->last_end_x = draw_end_x;
		sprite->last_perpendicular_distance = transform.y;
		if (transform.y <= 0)
			continue ;
		i.x = (size_t)ft_ssmax(draw_start_x, 0);
		while ((ssize_t)i.x < draw_end_x && i.x < fb->size.x)
		{
			if (transform.y >= zbuffer[i.x].perpendicular_distance)
			{
				i.x++;
				continue ;
			}
			sprite_px.x = inverse_lerp(draw_start_x, draw_end_x, i.x)
				* sprite_texture->size.x;
			i.y = (size_t)ft_ssmax(draw_start_y, 0);
			while ((ssize_t)i.y < draw_end_y && i.y < fb->size.y)
			{
				sprite_px.y = inverse_lerp(draw_start_y, draw_end_y, i.y)
					* sprite_texture->size.y;
				t_rgba	sprite_color = sprite_texture->pixels[sprite_px.y
					* sprite_texture->size.x + sprite_px.x];
				if (!(sprite_color.c.r == 255
					&& sprite_color.c.g == 255
					&& sprite_color.c.b == 255))
				{
					sprite_color.c.r /= (transform.y / 3.0f) + 1;
					sprite_color.c.g /= (transform.y / 3.0f) + 1;
					sprite_color.c.b /= (transform.y / 3.0f) + 1;
					if (sprite_color.c.a == 255)
						fb->pixels[i.y * fb->size.x + i.x] = sprite_color;
					else
						fb->pixels[i.y * fb->size.x + i.x] =
							blend_add(fb->pixels[i.y * fb->size.x + i.x],
							sprite_color);
				}
				i.y++;
			}
			i.x++;
		}
	}
}

static void	monsters(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_list_head			*pos;
	t_monster_entity	*monster;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		monster = (t_monster_entity*)((t_entity_node*)pos)->entity;
		frame_layer_transform(fb,
			&monster->name_text.target,
			ft_frame_transform(ft_vec2f(0.5f, 1.0f),
				ft_isize((monster->super.last_start_x + monster->super.last_end_x) / 2,
					monster->super.last_start_y),
				ft_vec2f(2.0f, 2.0f), 255),
			blend_invert);
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
	//frame_fill_blend(fb, ft_rgba(0, 0, 0, 10), blend_add);
	frame_fill(fb, ft_rgba(0, 0, 0, 255));
	floor_raycasting(self, fb, dir, plane);
	(void)ceiling_raycasting;
	// ceiling_raycasting(self, fb, dir, plane);
	walls_raycasting(self, fb);
	sprites(self, fb, dir, plane);
	monsters(self, fb);
	frame_layer_transform(fb, &self->crosshair,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(fb->size.x / 2, fb->size.y / 2),
			ft_vec2f(1.0f, 1.0f),
			255),
		blend_invert);
	frame_fill_blend(fb,
		ft_rgba(255, 255, 255,
			63 - ft_fmin((get_wall_time() - self->weapon.weapon.last_shot) * 10.0f, 1.0f) * 63),
		blend_add);
	raycasting_scene_render_weapon_display(self, fb);
}
