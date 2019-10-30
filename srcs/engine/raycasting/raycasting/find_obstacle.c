/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:09:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/07 22:40:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

// static t_ray	north_ray(const t_raycasting *const self,
// 					t_angle direction)
// {
// 	t_vec2f			pos;
// 	float			x_shift;
// 	float			y_shift;
// 	const t_image	*hit_texture;

// 	pos = self->position;
// 	y_shift = 1.0f - (pos.y - (int)pos.y);
// 	x_shift = y_shift / direction.tan;
// 	pos.x += x_shift;
// 	pos.y += y_shift;
// 	hit_texture = NULL;
// 	while (is_ray_in_map(self->map, pos))
// 	{
// 		if ((hit_texture = ray_hitting_texture(self->map, pos,
// 			NORTH, ft_vec2f(0.0f, 0.0f))))
// 			break ;
// 		pos.x += 1.0f / direction.tan;
// 		pos.y++;
// 	}
// 	return (ft_ray(self->position, pos, hit_texture,
// 		1.0f - (pos.x - (int)pos.x)));
// }

// static t_ray	east_ray(const t_raycasting *const self,
// 					const t_angle direction)
// {
// 	t_vec2f			pos;
// 	float			x_shift;
// 	float			y_shift;
// 	const t_image	*hit_texture;

// 	pos = self->position;
// 	x_shift = 1.0f - (pos.x - (int)pos.x);
// 	y_shift = x_shift * direction.tan;
// 	pos.x += x_shift;
// 	pos.y += y_shift;
// 	hit_texture = NULL;
// 	while (is_ray_in_map(self->map, pos))
// 	{
// 		if ((hit_texture = ray_hitting_texture(self->map, pos,
// 			EAST, ft_vec2f(0.0f, 0.0f))))
// 			break ;
// 		pos.x++;
// 		pos.y += direction.tan;
// 	}
// 	return (ft_ray(self->position, pos, hit_texture,
// 		pos.y - (int)pos.y));
// }

// static t_ray	south_ray(const t_raycasting *const self,
// 					const t_angle direction)
// {
// 	t_vec2f			pos;
// 	float			x_shift;
// 	float			y_shift;
// 	const t_image	*hit_texture;

// 	pos = self->position;
// 	y_shift = -(pos.y - (int)pos.y);
// 	x_shift = y_shift / direction.tan;
// 	pos.x += x_shift;
// 	pos.y += y_shift;
// 	hit_texture = NULL;
// 	while (is_ray_in_map(self->map, pos))
// 	{
// 		if ((hit_texture = ray_hitting_texture(self->map, pos,
// 			SOUTH, ft_vec2f(0.0f, -1.0f))))
// 			break ;
// 		pos.x -= 1.0f / direction.tan;
// 		pos.y--;
// 	}
// 	return (ft_ray(self->position, pos, hit_texture,
// 		pos.x - (int)pos.x));
// }

// static t_ray	west_ray(const t_raycasting *const self,
// 					const t_angle direction)
// {
// 	t_vec2f			pos;
// 	float			x_shift;
// 	float			y_shift;
// 	const t_image	*hit_texture;

// 	pos = self->position;
// 	x_shift = -(pos.x - (int)pos.x);
// 	y_shift = x_shift * direction.tan;
// 	pos.x += x_shift;
// 	pos.y += y_shift;
// 	hit_texture = NULL;
// 	while (is_ray_in_map(self->map, pos))
// 	{
// 		if ((hit_texture = ray_hitting_texture(self->map, pos,
// 			WEST, ft_vec2f(-1.0f, 0.0f))))
// 			break ;
// 		pos.x--;
// 		pos.y -= direction.tan;
// 	}
// 	return (ft_ray(self->position, pos, hit_texture,
// 		1.0f - (pos.y - (int)pos.y)));
// }

// t_ray			find_obstacle(const t_raycasting *const self,
// 					const float fisheye_cos,
// 					const t_angle direction)
// {
// 	t_ray	horizontal_ray;
// 	t_ray	vertical_ray;

// 	if (direction.cos >= 0)
// 		horizontal_ray = east_ray(self, direction);
// 	else
// 		horizontal_ray = west_ray(self, direction);
// 	if (direction.sin >= 0)
// 		vertical_ray = north_ray(self, direction);
// 	else
// 		vertical_ray = south_ray(self, direction);
// 	if (horizontal_ray.distance < vertical_ray.distance)
// 	{
// 		horizontal_ray.distance *= fisheye_cos;
// 		return (horizontal_ray);
// 	}
// 	else
// 	{
// 		vertical_ray.distance *= fisheye_cos;
// 		return (vertical_ray);
// 	}
// }
