/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/20 19:39:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_SCENE_H
# define RAYCASTING_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/array.h"
# include "game/entities/player_entity.h"
# include "game/entities/image_entity.h"
# include "game/entities/camera_entity.h"
# include "game/entities/sprite_entity.h"
# include "game/entities/monster_entity.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"

/*
** Raycasting level scene
*/
typedef struct	s_raycasting_scene
{
	t_scene				super;
	t_map				map;
	t_rgb				ground_color;
	t_rgb				sky_color;
	t_frame				background;
	t_image				texture;
	t_frame				dinosaur;
	t_array				zbuffer;
	t_frame				last_frame;
	t_image_entity		*vignette_ref;
	t_player_entity		*player_ref;
	t_camera_entity		*camera_ref;
	t_monster_entity	*monster_ref;
	t_entity_list		sprite_entities;
	float				fov;
}				t_raycasting_scene;

typedef struct	s_raycasting_scene_args
{
	const t_window	*window;
}				t_raycasting_scene_args;

t_constructor	raycasting_scene(const t_window *const window);

t_result		init_raycasting_scene(t_raycasting_scene *const self,
					const t_raycasting_scene_args *const args);

void			raycasting_scene_update(t_raycasting_scene *const self);
void			raycasting_scene_render(t_raycasting_scene *const self,
					t_frame *const fb);

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
