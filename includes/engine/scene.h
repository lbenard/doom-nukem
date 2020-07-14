/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:56:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "containers/list.h"
# include "containers/string.h"
# include "engine/entity_list.h"
# include "engine/entity_node.h"
# include "engine/event_handler.h"
# include "engine/input.h"

/*
** Super-class for any scene object. Stores generic scene informations such as
** an entity batch and an event handler. Each scene has a specific name that
** is shown as the current window title.
*/
typedef struct	s_scene
{
	t_module			module;
	t_string			name;
	t_entity_list		entities;
	t_event_handler		input_manager;
	t_input				input;
	void				(*update_fn)();
	void				(*render_fn)();
}				t_scene;

t_result		init_scene(t_scene *const self,
					const char *const name,
					void (*update_fn)(),
					void (*render_fn)());
void			destroy_scene(t_scene *const self);

#endif
