/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lamp_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:04:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:46:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMP_ENTITY_H
# define LAMP_ENTITY_H

# include "game/entities/sprite_entity.h"

typedef struct	s_lamp_entity
{
	t_sprite_entity	super;
}				t_lamp_entity;

typedef struct	s_lamp_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_lamp_entity_args;

t_constructor	lamp_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_lamp_entity(t_lamp_entity *const self,
					t_lamp_entity_args *const args);

void			destroy_lamp_entity(t_lamp_entity *const self);

#endif
