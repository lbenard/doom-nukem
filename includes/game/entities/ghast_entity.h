/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghast_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 21:21:10 by lbenard          ###   ########.fr       */
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
	float				shoot_time;
	double				last_shot_time;
	t_bool				just_shoot;
	t_bool				move_side;
	t_vec3f				last_pos;
	t_vec3f				side_move;
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
void			shot_fireball(t_ghast_entity *self);

void			destroy_ghast_entity(t_ghast_entity *const self);

#endif
