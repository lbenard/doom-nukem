/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:08:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/30 23:16:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECTOR_SCENE_H
# define SECTOR_SCENE_H

# include "engine/scene.h"
# include "maths/vec2f.h"
# include "colors/rgb.h"
# include "engine/frame.h"
// # include "game/entities/camera_entity.h"
#include "engine/input.h"
#include "engine/image.h"

typedef struct	s_wall
{
	t_vec2f	a;
	t_vec2f	b;
	t_bool	is_portal;
	t_rgb	color;
	t_vec2f	size;
	t_vec2f	texture_tiling;
	t_frame	*texture_ref;
}				t_wall;

typedef struct	s_sector
{
	size_t	wall_number;
	t_wall	*walls;
}				t_sector;

typedef struct	s_sector_scene
{
	t_scene			super;
	t_sector		*sectors;
	t_sector		*current_sector;
	t_frame			wall_texture;
	// t_camera_entity	*camera_ref;
	t_input_id		w;
	t_input_id		a;
	t_input_id		s;
	t_input_id		d;
	t_input_id		left_arrow;
	t_input_id		right_arrow;
	struct s_camera
	{
		t_vec2f position;
		float	angle;
		t_vec2f direction_vector;
		float	fov;
		size_t	plan_width;
		t_vec2f	plan;
		float	camera_to_plan_dist;
		t_vec2f	to_plan;
	}		camera;
}				t_sector_scene;

t_constructor	sector_scene(void);

t_result		init_sector_scene(t_sector_scene *const self);

void			sector_scene_update(t_sector_scene *const self);
void			sector_scene_render(t_sector_scene *const self,
					t_frame *const fb);

void			destroy_sector_scene(t_sector_scene *const self);

#endif