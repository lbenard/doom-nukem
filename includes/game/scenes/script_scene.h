/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 00:40:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 21:41:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_SCENE_H
# define SCRIPT_SCENE_H

# include "engine/scene.h"
# include "engine/text.h"
# include "engine/window.h"

typedef struct	s_script_scene
{
	t_scene		super;
	t_window	*window;
	const char	*path;
	t_text		skip_text;
	const char	*paragraph1;
	char		*writing_paragraph1;
	t_text		paragraph1_text;
	const char	*paragraph2;
	char		*writing_paragraph2;
	t_text		paragraph2_text;
	t_frame		tig;
	double		last_keystroke;
	double		keystroke_time;
	double		text_finished_time;
	t_bool		skip;
	float		speed;
}				t_script_scene;

typedef struct	s_script_scene_args
{
	t_window	*window;
	const char	*path;
}				t_script_scene_args;

t_constructor	script_scene(t_window *const window,
					const char *path);

t_result		init_script_scene(t_script_scene *const self,
					t_script_scene_args *const args);

void			script_scene_update(t_script_scene *const self);
void			script_scene_render(t_script_scene *const self,
					t_frame *const fb);

void			destroy_script_scene(t_script_scene *const self);

t_callback_node	*new_skip_event(void);

#endif