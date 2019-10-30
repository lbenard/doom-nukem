/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/07 22:29:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_SCENE_H
# define RAYCASTING_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/raycasting.h"
# include "engine/frame.h"
# include "game/entities/player_entity.h"
# include "game/entities/image_entity.h"
# include "game/entities/minimap_entity.h"

/*
** Raycasting level scene
*/
typedef struct		s_raycasting_scene
{
	t_scene			super;
	t_map			map;
	t_rgb			ground_color;
	t_rgb			sky_color;
	t_frame			background;
	t_raycasting	renderer;
	sfImage			*texture;
	t_image_entity	*vignette_ref;
	t_player_entity	*player_ref;
}					t_raycasting_scene;

typedef struct		s_raycasting_scene_args
{
	const t_window	*window;
}					t_raycasting_scene_args;

t_hmodule_factory	raycasting_scene(const t_window *const window);

t_raycasting_scene	*new_raycasting_scene(
						const t_raycasting_scene_args *const args);

void				raycasting_scene_update(t_raycasting_scene *const self);
void				raycasting_scene_render(t_raycasting_scene *const self,
						t_frame *const fb);

void				free_raycasting_scene(t_raycasting_scene *const self);

#endif
