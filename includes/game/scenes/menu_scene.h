/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:38:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_SCENE_H
# define MENU_SCENE_H

# include "engine/window.h"
# include "engine/scene.h"
# include "engine/frame.h"
# include "colors/rgb.h"
# include "game/entities/button_entity.h"
# include "game/entities/image_entity.h"

/*
** Fancy main menu scene, with fancy moving stuff and a fancy vignette on top
** of it, and fancy buttons to start or stop the game. Isn't that fancy?
*/
typedef struct	s_menu_scene
{
	t_scene			super;
	t_usize			window_size;
	t_image_entity	*vignette_ref;
	t_image_entity	*title_ref;
	t_image_entity	*credits_ref;
	t_button_entity	*start_game_ref;
	t_button_entity	*close_game_ref;
}				t_menu_scene;

typedef struct	s_menu_scene_args
{
	const t_window	*window;
}				t_menu_scene_args;

t_constructor	menu_scene(const t_window *const window);

t_result		init_menu_scene(t_menu_scene *const self,
					const t_menu_scene_args *const args);

void			menu_scene_update(t_menu_scene *const self);
void			menu_scene_render(t_menu_scene *const self,
					t_frame *const fb);

void			destroy_menu_scene(t_menu_scene *const self);

#endif
