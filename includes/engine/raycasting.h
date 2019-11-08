/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:44:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <SFML/Graphics.h>
# include "containers/module.h"
# include "types.h"
# include "containers/list.h"
# include "engine/array.h"
# include "engine/map.h"
# include "maths/vec2f.h"

typedef enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_direction;

/*
** Represents a ray, and which wall/texture is has encountered
*/
typedef struct	s_ray
{
	t_vec2f			start;
	t_vec2f			hit;
	t_wall			*wall;
	float			perpendicular_distance;
	float			texture_ratio;
	// const t_image	*texture;
}				t_ray;

t_ray			ft_ray(const t_vec2f player_position,
					const t_vec2f hit_position,
					const t_image *texture,
					const float texture_ratio);
t_bool			is_ray_in_map(const t_map *const map,
					const t_vec2f pos);
const t_image	*ray_hitting_texture(const t_map *const map,
					const t_vec2f pos,
					const t_direction direction,
					const t_vec2f shift);

/*
** Trigonometric values for specific angles
*/
typedef struct	s_angle
{
	float	rad;
	float	cos;
	float	sin;
	float	tan;
}				t_angle;

t_angle			ft_angle(float rad);

/*
** Raycasting module. Fire rays for every columns on-screen and store
** informations for any other modules that could need them
*/
typedef struct	s_raycasting
{
	t_module	module;
	t_map		*map;
	t_array		columns;
	size_t		columns_number;
	t_vec2f		pos;
	t_vec2f		dir;
	t_vec2f		plane;
}				t_raycasting;

typedef struct	s_raycasting_args
{
	t_usize	window_size;
	t_map	*map;
}				t_raycasting_args;

t_constructor	raycasting(const t_usize window_size, t_map *const map);

t_result		init_raycasting(t_raycasting *const self,
					const t_raycasting_args *const args);

void			raycasting_update(t_raycasting *const self);
t_ray			find_obstacle(const t_raycasting *const self,
					const float fisheye_cos,
					const t_angle direction);

void			destroy_raycasting(t_raycasting *const self);

#endif
