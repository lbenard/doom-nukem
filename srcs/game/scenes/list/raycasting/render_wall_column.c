/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:24:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:35:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

static t_rgba	color(const t_raycasting_scene *const self,
					const t_frame *const texture,
					const t_ray *const ray,
					const float vertical)
{
	t_rgba	ret;
	float	darkness_value;
	float	time;
	t_u8	opacity;
	float	luminosity;

	time = get_wall_time() - self->weapon.last_shot;
	ret = texture->pixels[(int)(ray->horizontal_ratio * texture->size.x)
		+ (int)(vertical * texture->size.y) * texture->size.x];
	opacity = ret.c.a;
	if (time >= 0.0f && time <= 0.3f)
		darkness_value = 2.0f * (time * 3.33f);
	else
		darkness_value = 2.0f;
	ret = get_lerp_col(ret, ray->perpendicular_distance, darkness_value);
	ret.c.a = opacity;
	luminosity = raycasting_scene_luminosity_from_light_sources(self,
		ft_vec3f(ray->wall_hit.x, ray->wall_hit.y, 0.5f));
	ret.c.r += (255 - ret.c.r) * luminosity / 6.0f * 0.984f;
	ret.c.g += (255 - ret.c.g) * luminosity / 6.0f * 0.949f;
	ret.c.b += (255 - ret.c.b) * luminosity / 6.0f * 0.8f;
	return (ret);
}

void			raycasting_scene_render_wall_column(
					const t_raycasting_scene *const self,
					t_frame *const fb,
					t_ray *const ray,
					const t_frame *const texture)
{
	float	size;
	ssize_t	start_y;
	ssize_t	end_y;
	size_t	y;
	t_rgba	result;

	size = (float)fb->size.x / ray->perpendicular_distance
		* ((float)fb->size.y / fb->size.x);
	start_y = (ssize_t)(fb->size.y) / 2 - (0.5f
		- self->entities.player_ref->super.transform.position.z) * size
		+ self->entities.player_ref->super.transform.rotation.x;
	end_y = start_y + size;
	y = (size_t)ft_ssmax(start_y, 0);
	while ((ssize_t)y < end_y && y < fb->size.y)
	{
		result = color(self, texture, ray, inverse_lerp(start_y, end_y, y));
		if (result.c.a != 255)
			fb->pixels[fb->size.x * y + self->raycasting.x] =
				blend_add(
					fb->pixels[fb->size.x * y + self->raycasting.x],
					result);
		else
			fb->pixels[fb->size.x * y + self->raycasting.x] = result;
		y++;
	}
}
