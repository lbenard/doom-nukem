/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghast_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 18:53:50 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GHAST_ENTITY_H
# define GHAST_ENTITY_H

# include "game/entities/monster_entity.h"
# include "engine/animation.h"
# include "game/entities/fireball_entity.h"

typedef struct	s_ghast_entity
{
	t_monster_entity	super;
	t_fireball_entity	fireball;
	float				shoot_time;
	double				last_shot_time;
}				t_ghast_entity;

typedef struct	s_ghast_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_ghast_entity_args;

t_constructor	ghast_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_ghast_entity(t_ghast_entity *const self,
					const t_ghast_entity_args *const args);

void			ghast_entity_update(t_ghast_entity *const self);

void			destroy_ghast_entity(t_ghast_entity *const self);

#endif