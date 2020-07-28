/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weird_alien_entity.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:14:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEIRD_ALIEN_ENTITY_H
# define WEIRD_ALIEN_ENTITY_H

# include "game/entities/monster_entity.h"
# include "engine/animation.h"

typedef struct	s_weird_alien_entity
{
	t_monster_entity	super;
}				t_weird_alien_entity;

typedef struct	s_weird_alien_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_weird_alien_entity_args;

t_constructor	weird_alien_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_weird_alien_entity(t_weird_alien_entity *const self,
					const t_weird_alien_entity_args *const args);

void			weird_alien_entity_update(t_weird_alien_entity *const self);

void			destroy_weird_alien_entity(t_weird_alien_entity *const self);

#endif