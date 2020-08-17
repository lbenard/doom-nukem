/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medikit_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:31:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 00:21:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIKIT_ENTITY_H
# define MEDIKIT_ENTITY_H

# include "game/entities/sprite_entity.h"

typedef struct	s_medikit_entity
{
	t_sprite_entity	super;
}				t_medikit_entity;

typedef struct	s_medikit_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_medikit_entity_args;

t_constructor	medikit_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_medikit_entity(t_medikit_entity *const self,
					t_medikit_entity_args *const args);

void			medikit_entity_update(t_medikit_entity *const self);

void			destroy_medikit_entity(t_medikit_entity *const self);

#endif
