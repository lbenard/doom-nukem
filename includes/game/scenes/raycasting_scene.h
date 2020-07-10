/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 22:16:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_SCENE_H
# define RAYCASTING_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/array.h"
# include "engine/sound.h"
# include "game/entities/player_entity.h"
# include "game/entities/image_entity.h"
# include "game/entities/camera_entity.h"
# include "game/entities/sprite_entity.h"
# include "game/entities/monster_entity.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"

typedef struct	s_weapon
{
	char	*name;
	size_t	ammo;
	size_t	clip;
	size_t	clip_size;
	float	damage;
	float	shoot_time;
	double	last_shot;
}				t_weapon;

/*
** Raycasting level scene
*/
typedef struct	s_raycasting_scene
{
	t_scene				super;
	t_map				map;
	t_rgb				ground_color;
	t_rgb				sky_color;
	t_frame				texture;
	t_frame				crosshair;
	t_array				zbuffer;
	t_player_entity		*player_ref;
	t_weapon			weapon;
	t_input_id			shoot_input;
	t_camera_entity		*camera_ref;
	t_monster_entity	*monster_ref;
	t_entity_list		sprite_entities;
	t_entity_list		monster_entities;
	t_window			*window_ref;
	t_sound				pistol;
	float				fov;
}				t_raycasting_scene;

typedef struct	s_raycasting_scene_args
{
	t_window	*window;
	const char	*path;
}				t_raycasting_scene_args;

t_constructor	raycasting_scene(t_window *const window,
					const char *path);

t_result		init_raycasting_scene(t_raycasting_scene *const self,
					t_raycasting_scene_args *const args);

void			raycasting_scene_update(t_raycasting_scene *const self);
void			raycasting_scene_render(t_raycasting_scene *const self,
					t_frame *const fb);

t_result		raycasting_scene_add_monster(t_raycasting_scene *const self,
					t_constructor constructor);

void			raycasting_scene_set_weapon_pistol(
					t_raycasting_scene *const self);
void			raycasting_scene_set_weapon_minigun(
					t_raycasting_scene *const self);
void			raycasting_scene_shoot(t_raycasting_scene *const self);

void			destroy_raycasting_scene(t_raycasting_scene *const self);

/*
** Utils
*/

typedef struct	s_ray
{
	t_vec2f			hit;
	t_wall			*wall;
	float			perpendicular_distance;
	float			horizontal_ratio;
}				t_ray;

// typedef struct	s_casting
// {
// 	t_vec2i	pos;
// 	t_vec2f	origin_to_side;
// 	t_vec2f	side_to_side;
// 	float	perpendicular_distance;
// }				t_casting;

t_ray			cast(const t_map *const map,
					const t_vec2f pos,
					const t_vec2f dir);

#endif
