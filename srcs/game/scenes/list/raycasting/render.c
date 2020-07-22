/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/22 03:37:00 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"
#include "maths/maths.h"
#include "engine/delta.h"
#include "game/entities/monster_entity.h"

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

void	display_hud(t_raycasting_scene *self, t_frame *const fb)
{
	int		perc_sprite;
	float	index_sprite;
	static double i;

	perc_sprite = 100 * self->player_ref->health / 150;
	index_sprite = ((float)self->hud_ray.heart_ss.grid_size.x / 100.0f) * perc_sprite;
	i += 0.05 + (float)((8 - index_sprite) / 100);
	if (i >= 6.283)
		i = 0;
	frame_layer_transform(fb, &self->hud_ray.heart_ss.sprite[8 - (int)index_sprite],
		ft_frame_transform(ft_vec2f(0.5f, 1.0f), ft_isize(fb->size.x / 2 - self->hud_ray.heart_ss.grid_size.x / 2,
			fb->size.y - 64), ft_vec2f(1 + cos(i - 1.571)*sin(i - 1.571)/(i - 1.571), 1 + cos(i - 1.571)*sin(i - 1.571)/(i - 1.571)), 255), blend_add);
	// printf("health = %d, perc = %d, index_sprite = %f\n", self->player_ref->health, perc_sprite, index_sprite);
	printf("costime = %f\n", i);
	// cos(x)+10*sin(2*x)/x
	// 2 + cosf(i) / 3, 2 + cosf(i) / 3

}

void		raycasting_scene_render(t_raycasting_scene *const self,
				t_frame *const fb)
{
	zbuffer(self, self->player_ref->dir, self->player_ref->plane);
	frame_fill(fb, ft_rgba(0, 0, 0, 255));
	floor_raycasting(self, fb, self->player_ref->dir, self->player_ref->plane);
	(void)ceiling_raycasting;
	// ceiling_raycasting(self, fb, self->player_ref->dir, self->player_ref->plane);
	walls_raycasting(self, fb);
	raycasting_scene_render_sprites(self, fb);
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
	display_hud(self, fb);
}
