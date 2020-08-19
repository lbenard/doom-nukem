/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:22:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 23:04:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

static t_rgba	color(const t_raycasting_scene *const self,
					const t_ray *const ray,
					const float vertical)
{
	const t_frame	*texture;
	t_rgba			ret;
	float			darkness_value;
	float			time;

	time = get_wall_time() - self->weapon.last_shot;
	if (ray->hit.x >= self->map.size.x || ray->hit.y >= self->map.size.y
		|| ray->hit.x < 0 || ray->hit.y < 0)
		texture = &self->assets.floor;
	else
		texture = self->map.map[(int)ray->hit.y * self->map.size.x
			+ (int)ray->hit.x].texture_ref;
	ret = texture->pixels[(int)(ray->horizontal_ratio * texture->size.x)
		+ (int)(vertical * texture->size.y) * texture->size.x];
	if (time >= 0.0f && time <= 0.3f)
		darkness_value = 2.0f * (time * 3.33f);
	else
		darkness_value = 2.0f;
	ret = get_lerp_col(ret, ray->perpendicular_distance, darkness_value);
	return (ret);
}

void			raycasting_scene_render_walls(t_raycasting_scene *const self,
					t_frame *const target)
{
	t_usize	i;
	float	size;
	ssize_t	start_y;
	ssize_t	end_y;
	t_ray	*ray;

	i.x = 0;
	while (i.x < target->size.x)
	{
		ray = &((t_ray*)self->zbuffer.array)[i.x];
		size = (float)target->size.x / ray->perpendicular_distance
			* ((float)target->size.y / target->size.x);
		start_y = (ssize_t)(target->size.y) / 2 - (0.5f
			- self->entities.player_ref->super.transform.position.z) * size
			+ self->entities.player_ref->super.transform.rotation.x;
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
