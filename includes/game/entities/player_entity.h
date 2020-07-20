/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:42:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 22:37:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ENTITY_H
# define PLAYER_ENTITY_H

# include "engine/entity.h"
# include "engine/entity_node.h"
# include "engine/scene.h"
# include "engine/map.h"
# include "engine/input.h"

/*
** Corners collision detection
*/
typedef struct	s_corners
{
	t_bool			ne;
	t_bool			se;
	t_bool			so;
	t_bool			no;
}				t_corners;

t_corners		ft_corners(t_bool ne, t_bool se, t_bool so, t_bool no);

/*
** Player entity. The player can move around with WASD + up and down arrows,
** and turn with left-right arrows. They can sprint by holding the Shift button.
** The player has collision detection and cannot walls
*/
typedef struct	s_player_entity
{
	t_entity		super;
	t_vec3f			velocity;
	t_bool			is_moving;
	const t_map		*map_ref;
	float			speed;
	float			fov;
	t_vec2f			dir;
	t_vec2f			plane;
	t_input_id		forward;
	t_input_id		backward;
	t_input_id		left;
	t_input_id		right;
	t_input_id		turn_left;
	t_input_id		turn_right;
	t_input_id		camera_up;
	t_input_id		camera_down;
	t_input_id		sprint;
}				t_player_entity;

typedef struct	s_player_entity_args
{
	const t_map		*map;
	float			fov;
}				t_player_entity_args;

t_constructor	player_entity(const t_map *const map, const float fov);

t_result		init_player_entity(t_player_entity *const self,
					const t_player_entity_args *const args);

void			player_entity_update(t_player_entity *const self);
t_bool			is_colliding(const t_map *const map,
					const t_vec2f move,
					const float box_size,
					t_corners *const box_corner);

t_bool			is_vertical_collide(const t_corners box);
t_bool			is_horizontal_collide(const t_corners box);
t_bool			is_corner_collide(const t_corners box_corner,
					t_vec3f *const vel);

t_vec3f			north_east_rebound(const t_vec3f vel);
t_vec3f			south_east_rebound(const t_vec3f vel);
t_vec3f			south_west_rebound(const t_vec3f vel);
t_vec3f			north_west_rebound(const t_vec3f vel);

void			destroy_player_entity(t_player_entity *const self);

#endif
