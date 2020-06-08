/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 01:50:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/01 14:51:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_ENTITY_H
# define CAMERA_ENTITY_H

# include "engine/entity.h"
# include "engine/frame.h"
# include "engine/input.h"

/*
** First person camera with WASD movements
*/
typedef struct	s_camera_entity
{
	t_entity	super;
	t_input		input;
}				t_camera_entity;

typedef struct	s_camera_entity_args
{
	t_vec2f	spawn_pos;
	float	direction;
}				t_camera_entity_args;

t_constructor	camera_entity(const t_vec2f spawn_pos, const float direction);

t_result		init_camera_entity(t_camera_entity *const self,
					const t_camera_entity_args *const args);

void			camera_entity_update(t_camera_entity *const self);
void			camera_entity_render(t_camera_entity *const self,
					t_frame	*const frame);

void			destroy_camera_entity(t_camera_entity *const self);

#endif