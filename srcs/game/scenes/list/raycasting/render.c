/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:47:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"

#include <stdio.h>

t_rgba	color(t_raycasting_scene *self,
			const t_ray *const ray,
			const t_frame *const fb,
			int vertical_start)
{
	t_rgba			*texture;
	const t_image	*used_texture;
	t_rgba			ret;

	if (ray->wall->north_texture_ref)
		used_texture = ray->wall->north_texture_ref;
	else
		used_texture = &self->texture;
	texture = (t_rgba*)sfImage_getPixelsPtr(used_texture->image);
	ret.integer = texture[(int)(ray->texture_ratio * used_texture->size.x)
		+ (int)(((vertical_start) / (fb->size.y / ray->perpendicular_distance)
		* used_texture->size.y)) * used_texture->size.x].integer;
	ret.c.r /= (ray->perpendicular_distance / 3.0f) + 1;
	ret.c.g /= (ray->perpendicular_distance / 3.0f) + 1;
	ret.c.b /= (ray->perpendicular_distance / 3.0f) + 1;
	return (ret);
}

void	raycasting_scene_render(t_raycasting_scene *const self,
			t_frame *const fb)
{
	t_usize			i;
	size_t			size;
	size_t			wall_start;

	raycasting_update(&self->renderer);
	frame_layer(fb, &self->background, ft_isize(0, 0), blend_add);
	i = ft_usize(0, 0);
	while (i.x < self->renderer.columns_number)
	{
		size = fb->size.y / ((t_ray*)self->renderer.columns.array)[i.x].perpendicular_distance;
		i.y = 0;
		wall_start = (fb->size.y - size) / 2.0f;
		while (i.y < size && i.y < fb->size.y)
		{
			((t_u32*)fb->frame.array)[fb->size.x * (wall_start + i.y) + i.x] =
				color(self, ((t_ray*)self->renderer.columns.array) + i.x, fb,
				i.y + ((size > fb->size.y) ? (size - fb->size.y) * 0.5
				: 0.0f)).integer;
			i.y++;
		}
		i.x++;
	}
	// minimap_entity_render(self->minimap_ref, fb);
	// image_entity_render(self->vignette_ref, fb);
}

// void	raycasting_scene_render(t_raycasting_scene *const self,
// 			t_frame *const fb)
// {
// 	size_t	i;
// 	int		line_height;
// 	int		j;
// 	t_ray	*ray;

// 	i = 0;
// 	raycasting_update(&self->renderer);
// 	frame_layer(fb, &self->background, ft_isize(0, 0), blend_add);
// 	while (i < self->renderer.columns_number)
// 	{
// 		ray = &((t_ray*)self->renderer.columns.array)[i];
// 		line_height = fb->size.y / ray->perpendicular_distance;
// 		int	draw_start = -line_height / 2 + fb->size.y / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		int draw_end = line_height / 2 + fb->size.y / 2;
// 		if (draw_end >= (int)fb->size.y)
// 			draw_end = fb->size.y - 1;
// 		j = draw_start;
// 		// t_rgba			*texture = (t_rgba*)sfImage_getPixelsPtr(ray->wall->north_texture_ref);
// 		// sfVector2u		texture_size = sfImage_getSize(ray->wall->north_texture_ref);
// 		while (j <= draw_end)
// 		{
// 			((t_u32*)fb->frame.array)[j * fb->size.x + i] =
// 				color(self, ray, fb, draw_start).integer;
// 				// texture[(j - draw_start) / (draw_end - draw_start) * texture_size.x + i / self->renderer.columns_number * texture_size.x].integer;
// 			// ((t_u32*)fb->frame.array)[j * fb->size.x + i] = texture[0].integer;
// 				// ft_rgba(255, 255, 255, 255).integer;
// 			j++;
// 		}
// 		i++;
// 	}
// 	image_entity_render(self->vignette_ref, fb);
// }
